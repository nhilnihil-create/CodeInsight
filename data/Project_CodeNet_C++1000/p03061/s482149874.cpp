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
	vi arr(n);
	for(int &i:arr)cin>>i;
	vi l(n),r(n);
	int lc=arr[0],rc=arr[n-1];
	REP(i,0,n-1) {
		lc=__gcd(lc,arr[i]);
		l[i]=lc;
	}
	for(int i=n-1;i>=0;i--) {
		rc= __gcd(rc,arr[i]);
		r[i]=rc;
	}
	int mx = max(r[1],l[n-2]);
	REP(i,1,n-2) {
		int gc = __gcd(l[i-1],r[i+1]);
		mx=max(mx,gc);
	}
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
