
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
const int mod = 998244353;
const int INF = 0x3f3f3f3f;
long long  inv(long long b)
{
	if(b == 1)
	return 1;
	return (mod-mod/b)*inv(mod%b)%mod;
}
long long fac[N];
long long C(long long n,long long m)
{
	long long t = (fac[m]*fac[n-m])%mod;
	return (fac[n]*inv(t))%mod;
}
int main()
{
	long long n,i,a,b,k;
	fac[0] = 1;
	fac[1] = 1;
	for(i = 2;i <= 3e5+5;i++)
	    fac[i] = (fac[i-1]*i)%mod;
	cin>>n>>a>>b>>k;
	long long res = 0;
	for(i = 0;i <= n;i++)
	{
		if(k-(i*a) >= 0 && (k-a*i)%b == 0 && (k-a*i)/b <= n)
		{
		    res = (res+C(n,i)*C(n,(k-a*i)/b)%mod)%mod;
		}
	}
	cout<<res<<endl;

}
