/*
ID: anonymo14
TASK: wormhole
LANG: C++                 
*/
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<pair<int,int>> vpii;

#define F first
#define S second
#define PU push
#define PUF push_front
#define PUB push_back
#define PO pop
#define POF pop_front
#define POB pop_back

#define REP(i,a,b) for(int i=a; i<=b; i++)

#define MOD 1000000007

string gs(int n){
	string ans = to_string(n);
	while(ans.length()<6)ans="0"+ans;
	return ans;
}

void solve(int test_case) {//228
	int n,m;
	cin>>n>>m;//{PID, Y, CID}
	vector<vpii> arr(n+1, vpii());
	vector<string> ans(m+1);
	REP(i,1,m) {
		int p,y;
		cin>>p>>y;
		arr[p].PUB({y,i});
	}
	REP(i,1,n)sort(arr[i].begin(),arr[i].end());
	REP(i,1,n) {
		string pid = gs(i);
		REP(j,0,(int)arr[i].size()-1){
			ans[arr[i][j].S]=pid+gs(j+1);
		}
	}
	REP(i,1,m)cout<<ans[i]<<"\n";
}

int main() {
	
	////// FILE BASED IO////
	//freopen("wormhole.in", "r", stdin);
	//freopen("wormhole.out", "w", stdout);
	///////////////
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t=1;
	//cin>>t;
	REP(i,1,t) {
		solve(i);
	}
	return 0;
}	
