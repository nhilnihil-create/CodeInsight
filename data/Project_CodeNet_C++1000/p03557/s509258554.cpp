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
	vi a(n),b(n),c(n);
	vector<pair<ll,ll>> brr(n);
	for(int &i:a)cin>>i;
	for(int &i:b)cin>>i;
	for(int &i:c)cin>>i;
	sort(c.begin(),c.end());
	sort(b.begin(),b.end());
	REP(i,0,n-1) {
		//cerr<<c.end()-upper_bound(c.begin(),c.end(),b[i])<<"\n";
		brr[i]={b[i],c.end()-upper_bound(c.begin(),c.end(),b[i])};
	}
	for(int i=n-2;i>=0;i--) {
		//cerr<<brr[i].S+brr[i+1].S<<"\n";
		brr[i]={brr[i].F,brr[i].S+brr[i+1].S};
	}
	ll sum = 0;
	for(int i:a) {
		pair<ll,ll> p ={i,LONG_MAX};
		//cerr<<brr[(upper_bound(brr.begin(),brr.end(),p)-brr.begin())].S<<"\n";
		auto up = upper_bound(brr.begin(),brr.end(),p);
		if(up-brr.begin()<n)
		sum+=brr[(up-brr.begin())].S;
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
