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

void solve(int test_case) {//220
	int h,w;
	cin>>h>>w;
	vector<string> arr(h);
	for(auto &i:arr)cin>>i;
	vector<vi> ans(h,vi(w,0));
	REP(i,0,h-1) {
		REP(j,0,w-1) {
			if(arr[i][j]=='#'){ans[i][j]=-1;continue;}
			if(j-1>=0&&arr[i][j-1]=='#')ans[i][j]++;
			if(j+1!=w&&arr[i][j+1]=='#')ans[i][j]++;
			if(i-1>=0&&arr[i-1][j]=='#')ans[i][j]++;
			if(i+1!=h&&arr[i+1][j]=='#')ans[i][j]++;
			if(j-1>=0&&i-1>=0&&arr[i-1][j-1]=='#')ans[i][j]++;
			if(j-1>=0&&i+1!=h&&arr[i+1][j-1]=='#')ans[i][j]++;
			if(j+1!=w&&i-1>=0&&arr[i-1][j+1]=='#')ans[i][j]++;
			if(j+1!=w&&i+1!=h&&arr[i+1][j+1]=='#')ans[i][j]++;
		}
	}
	REP(i,0,h-1){REP(j,0,w-1){if(ans[i][j]==-1)cout<<"#";else cout<<ans[i][j];}cout<<"\n";}
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
