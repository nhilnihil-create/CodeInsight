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
	int a[5] = {0,0,1,1,1};
	int b[5] ={0};
	map<char,ll> m;
	int n;
	cin>>n;
	string s;
	for(int i = 0; i<n; i++)
	{
		cin>>s;
		m[s[0]]++;
	}
	b[0] = m['M'],b[1] = m['A'],b[2] = m['R'],b[3]=m['C'],b[4] = m['H'];
	ll ans = 0;
	do{
		ll t = 1;
		for(int i = 0; i<5; i++)
			if(a[i])
			t *= b[i];
		
		ans += t;
	}while(next_permutation(a,a+5));
	cout<<ans<<endl;
	return 0;
}