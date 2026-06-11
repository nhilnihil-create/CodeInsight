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

void solve(int test_case) {//228
	int h,w;
	cin>>h>>w;
	vector<vector<char>> arr(h,vector<char>(w));
	for(auto &a:arr)for(auto &b:a)cin>>b;
	REP(i,0,h-1) {
		REP(j,0,w-1) {
			if(arr[i][j]=='#') {
				if(i>0&&arr[i-1][j]=='#')continue;
				if(i<h-1 && arr[i+1][j]=='#')continue;
				if(j>0&&arr[i][j-1]=='#')continue;
				if(j<w-1 && arr[i][j+1]=='#')continue;
				cout<<"No";
				return;
			}
		}
	}
	cout<<"Yes";
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
