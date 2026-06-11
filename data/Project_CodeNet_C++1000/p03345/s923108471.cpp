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

void solve(int test_case) {//209
	ll a,b,c,k;
	cin>>a>>b>>c>>k;
	if(k&1) {
		ll ac = b+c;
		ll bc = a+c;
		ll cc = a+b;
		a=ac,b=bc,c=cc;
	}
	cout<<a-b;
}//b+c 2a+b+c 2a+3b+3c 6a+5b+5c 10a+11b+11c
 //c+a a+2b+c 3a+2b+3c 5a+6b+5c 11a+10b+11c
 //a+b a+b+2c 3a+3b+2c 5a+5b+6c 11a+11b+10c
 //5 9  19
 //4 10 18
 //5 9  19

int main() {
	
	////// FILE BASED IO////
	//freopen("wormhole.in", "r", stdin);
	//freopen("wormhole.out", "w", stdout);
	///////////////
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t=1;
	//cin>>t;
	//prefill();
	REP(i,1,t) {
		solve(i);
	}
	return 0;
}	
