#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PI 3.14159265358979
#define EPS 1e-8

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define endl "\n"
	 
const ll INF=(ll)2e18;
		
const ll mod =(ll)998244353;
const int N=2e5+5;

ll fac[300050]={0};	
long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}	

ll modinverse(ll a,ll m)
{
	return binpow(a,m-2,m);
}

ll ncr(ll a,ll b)
{
	return fac[a]* modinverse(fac[b],mod) %mod * modinverse(fac[a-b],mod) % mod;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n,a,b,k;
	cin>>n>>a>>b>>k;
	
	
	
	fac[0]=1;
	
	for(ll i=1;i<=300000;i++)
	{
		fac[i]=fac[i-1]*i;
		fac[i]%=mod;
	}
	ll ans2=0;
	
	for(ll i=0;i<=n;i++)
	{
		ll val=i*a;
		
		if(k>=(i*a) && (k-i*a)%b==0)
		{
			ll val1=i;
			ll val2=(k-i*a)/b;
			ll ans1;
			if(val2>n)
				continue;
			ans1=ncr(n,val1);
			ans1*=ncr(n,val2);
			ans1%=mod;
			ans2+=ans1;
			ans2%=mod;
		}
	}
	
	cout<<ans2;
	
	
}
