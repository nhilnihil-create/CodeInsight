#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef long double ld;
#define REP(i, a, b) for(ll i = ll(a); i <= ll(b); i++)
int main()
{
	ll n,f=0,cnt=2;
	cin>>n;
	set<ll> v;
	v.insert(n);
	while(1)
	{
		if(n%2==0)
		{
			n=n/2;
		}
		else
		{
			n=3*n+1;
		}
		if(v.count(n)==1)
		{
			f=1;
			break;
		}
		cnt++;
		v.insert(n);
	}
	//for (auto const& i: v) {
		//std::cout << i << " ";
	//}
	//cout<<endl<<"cnt "
	cout<<cnt;
}