#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef long double ld;
#define REP(i, a, b) for(ll i = ll(a); i <= ll(b); i++)
int main()
{
	ll n,m,x,cnt_O=0,cnt_N=0;
	vector<ll> a;
	cin>>n>>m>>x;
	a.resize(m);
	REP(i,0,m-1)
	{
		cin>>a[i];
	}
	REP(i,0,m-1)
	{
		if(x<a[i])
			cnt_O++;
		else
			cnt_N++;
	}
	cout<<min(cnt_O,cnt_N);
}