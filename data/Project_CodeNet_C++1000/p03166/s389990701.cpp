// Program.cpp

#include <bits/stdc++.h>
using namespace std;

typedef long long           ll;
typedef pair<int, int>      pii;
typedef vector<int>         vi;

#define fr(i, n)            for(int i=0; i<(n); ++i)
#define frC(i, n)           for(int i=0; (i<(n)) && (c); ++i)
#define frA(i, a, n)        for(int i=a; i<=(n); ++i)
#define frD(i, a, n)        for(int i=a; i>=(n); --i)
#define fill(a)             memset(a, 0, sizeof(a))
#define revsort(a, b)       sort(a, b, greater<int>())
#define dout                if(DEBUGGING) cout
#define dbg                 if(DEBUGGING) 
#define endl                "\n"

int DEBUGGING    =          0;
const int INF    =          1000000000;
const int MOD    =          1000000007;
const double PI  =          3.1415926535897932;
const double EPS =          1e-7;

void dfs(int s,vector<int>& used,vector<int>& dp, vector<int> adj[]){
	if(used[s] == 1)
		return;
	int max = -1;
	for(int i:adj[s]){
		dfs(i,used,dp,adj);
	}
	for(int i:adj[s]){
		if(max<dp[i])
			max = dp[i];
	}
	dp[s] = 1+max;
	used[s] = 1;
	return;
}

void solve(int TEST_CASE){
	int n,m;
	cin >> n >> m;
	vector<int> adj[n];
	int p,q;
	fr(i,m){
		cin >> p >> q;
		adj[p-1].push_back(q-1);
	}
	vector<int> used(n);
	vector<int> dp(n);
	fr(i,n){
		if(used[i] == 0){
			dfs(i,used,dp,adj);
		}
	}
	cout << *max_element(dp.begin(),dp.end()) << " ";
}

int main(int argc, char* argv[]){
    if(argc==2 && argv[1][1]=='v') DEBUGGING = 1;
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(cin.failbit);
    int nTestCases=1;
    //cin >> nTestCases;
    frA(i,1,nTestCases) solve(i);
    return 0;
}