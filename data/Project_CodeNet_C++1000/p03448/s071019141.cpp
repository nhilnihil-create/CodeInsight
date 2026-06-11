#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef long double ld;
#define REP(i, a, b) for(ll i = ll(a); i <= ll(b); i++)
int main()
{
	ll a,b,c,x,tmp,cnt=0;
	cin>>a>>b>>c>>x;
	REP(i,0,a)
	{
		REP(j,0,b)
		{
			REP(k,0,c)
			{
				tmp=i*500+j*100+k*50;
				if(tmp==x)
					cnt++;
			}
		}
	}
	cout<<cnt;
}