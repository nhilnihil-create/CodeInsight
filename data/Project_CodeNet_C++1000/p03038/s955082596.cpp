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

void solve(int test_case) {//221
	int n,m;
	cin>>n>>m;
	vi arr(n);
	for(int &i:arr)cin>>i;
	sort(arr.begin(),arr.end());
	vpii bc(m);
	for(auto &i:bc) {
		cin>>i.S>>i.F;
		//cerr<<i.S<<i.F;
	}
	sort(bc.rbegin(),bc.rend());
	ll sum = 0;int pos=0;
	for(int i:arr) {
		//cerr<<pos<<" "<<m<<" "<<i<<" "<<bc[pos].F;
		if(pos!=m&&i<bc[pos].F) {
			sum+=bc[pos].F;
			bc[pos].S--;
			if(bc[pos].S==0)pos++;
		} else sum+=i;
	}
	cout<<sum;
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
