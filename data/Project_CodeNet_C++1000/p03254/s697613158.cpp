#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef long double ld;
#define REP(i, a, b) for(ll i = ll(a); i <= ll(b); i++)
int main()
{
	ll n,x,cnt=0,p;
	cin>>n>>x;
	vector<ll> v;
	REP(i,0,n-1)
	{
		cin>>p;
		v.push_back(p);
	}
	sort(v.begin(),v.end());
	REP(i,0,n-1)
	{
		if(v[i]>x)
			break;
		x=x-v[i];
		cnt++;
		v[i]=0;
		if(x<v[i+1])
			break;
	}
	ll total=accumulate(v.begin(),v.end(),0);
	if(x>total)
		cnt--;
	cout<<cnt;
}