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
typedef vector<ll> vll;
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

void solve(int test_case) {
	int n;
	cin>>n;
	vector<vector<bool>> f(n,vector<bool>(10));
	REP(i,0,n-1) {
		REP(j,0,9) {
			int val;
			cin>>val;
			f[i][j]=val==1;
		}
	}
	vector<vi> p(n,vi(11));
	int sum = INT_MIN;
	for(auto &i:p)for(auto &j:i)cin>>j;
	for(int i=1;i<(1<<10);i++) {
		vi now(n,0);
		for(int j=0;j<10;j++) {
			if((i>>j)&1) {
				REP(k,0,n-1) {
					if(f[k][j])now[k]++;
				}
			}
		}
		int ns = 0;
		REP(j,0,n-1)ns+=p[j][now[j]];
		sum = max(ns,sum);
	}
	cout<<sum;
}//2^10 all samples except none. find sum for all possible options;

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
