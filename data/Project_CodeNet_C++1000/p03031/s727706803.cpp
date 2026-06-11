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

void solve(int test_case) {//233
	int n,m;
	cin>>n>>m;
	vector<vector<bool>> arr(m, vector<bool>(n, false));
	REP(i,0,m-1) {
		int k;
		cin>>k;
		while(k--) {
			int val;
			cin>>val;
			arr[i][val-1]=1;
		}
	}
	vi pa(m);int cnt = 0;
	REP(i,0,m-1)cin>>pa[i],pa[i]%=2;
	for(int i=0;i<1<<n;i++) {
		vector<bool> bulbs(n,false);
		for(int j=0;j<n;j++) {
			if((i>>j)&1)bulbs[j]=1;
		}
		int bs = 0;
		REP(j,0,m-1) {
			int tc = 0;
			REP(k,0,n-1){
				if(bulbs[k]&&arr[j][k])tc++;
			}
			if(tc%2==pa[j])bs++;
			else break;
		}
		if(bs==m)cnt++;
	}
	cout<<cnt;
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
