#include <bits/stdc++.h>
using namespace std;

const long long mod=1000000007LL;

long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	long long iv[n+5]={};
	for (int i = 1; i < n+5; ++i)
	{
		iv[i]=modinv(i,mod);
	}
	long long s[n+5]={};
	for (int i = 1; i < n+5; ++i)
	{
		s[i]=s[i-1]+iv[i];
		s[i]%=mod;
	}
	long long a,ans=0LL;
	for (int i = 1; i <= n; ++i)
	{
		cin>>a;
		ans+=a*(s[i]+s[n-i+1]-1LL)%mod;
		ans%=mod;
	}
	for (long long i = 1; i <= n; ++i)
	{
		ans*=i;
		ans%=mod;
	}
	cout<<ans<<endl;
	return 0;
}
