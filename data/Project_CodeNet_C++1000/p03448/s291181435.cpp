#define _USE_MATH_DEFINES //M_PI, M_E
#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long int
#define ar array
#define pb push_back
ll power(ll a,ll b){ll r=1;for(;b;b>>=1){if(b&1)r=r*a%mod;a=a*a%mod;}return r;}
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int a,b,c,x;
	cin>>a>>b>>c>>x;
	int ans = 0;
	for(int i = 0; i<=a; i++)
		for(int j = 0; j<=b;j++)
			for(int k =0 ;k<=c;k++)
			{
				if(i*500+j*100+k*50==x) ans++;
			}
			cout<<ans<<endl;
	return 0;
}