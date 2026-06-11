#define _USE_MATH_DEFINES //M_PI, M_E
#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long int
#define ar array
#define pb push_back
ll power(ll a,ll b){ll r=1;for(;b;b>>=1){if(b&1)r=r*a%mod;a=a*a%mod;}return r;}
using namespace std;
const int n = int(1e5)+5;
bool primes[n];

void sieve()
{
	primes[0]=primes[1] = 0;
	for(int i = 2; i<=sqrt(n); i++)
		if(primes[i])
			for(int j = i*2; j<n; j+=i)
				primes[j] = 0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	memset(primes,1,n);
	sieve();
	int q,l,r;
	cin>>q;
	int a[n] = {0};
	for(int i = 3; i<n; i+=2)
	{
		if(primes[i] && primes[((i+1)/2)])
			a[i]++;
	}
	for(int i = 2; i<n; i++)a[i] += a[i-1];
	while(q--)
	{
		cin>>l>>r;
		cout<<a[r]-a[l-1]<<'\n';
	}
	return 0;
}