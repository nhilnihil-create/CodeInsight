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

void solve(int test_case) {//227
	int n;
	cin>>n;
	vi a(n),b(n);
	for(int &i:a)cin>>i;
	for(int &i:b)cin>>i;
	for(int i=1;i<n;i++)a[i]+=a[i-1];
	for(int i=n-2;i>=0;i--) {
		b[i]+=b[i+1];
	}
	int mx=0;
	REP(i,0,n-1) mx=max(mx,a[i]+b[i]);
	cout<<mx;
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
