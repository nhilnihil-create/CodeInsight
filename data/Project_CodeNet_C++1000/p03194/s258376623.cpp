/*
Look at the star
Look at the shine for U
*/
#include<bits/stdc++.h>
#define ll long long
#define PII pair<int,int>
#define sl(x) scanf("%lld",&x)
using namespace std;
const int N = 1e6+5;
const int mod = 1e9+7;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1);
ll inv(ll b){if(b==1)return 1; return (mod-mod/b)*inv(mod%b)%mod;}
ll fpow(ll n,ll k){ll r=1;for(;k;k>>=1){if(k&1)r=r*n;n=n*n;}return r;}

int main()
{
	ll n,p,i,j,k;
	cin >> n >> p;
	if(n == 1)
	{
		cout << p << endl;
		return 0;
	}
	for(i = 0;fpow(2,i) <= p;i++);
	if(i < n)
	{
		cout << 1 << endl;
		return 0;
	}
	ll maxx = 1;
	for(i = 1;fpow(i,n) <= p;i++)
	{
		ll now = fpow(i,n);
		if(p%now==0)
			maxx = i;
	}
	cout << maxx << endl;
	return 0;
}