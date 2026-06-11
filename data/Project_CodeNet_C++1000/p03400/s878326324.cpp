#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef long double ld;
#define REP(i, a, b) for(ll i = ll(a); i <= ll(b); i++)
int main()
{
	ll n,x,d,cnt=0;
	cin>>n>>d>>x;
	REP(i,1,n)
	{
		ll a;
		cin>>a;
		cnt+=((d-1)/a)+1;
	}
	cout<<cnt+x;
}