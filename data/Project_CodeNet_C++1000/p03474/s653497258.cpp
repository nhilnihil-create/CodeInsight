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
	int a,b;
	cin>>a>>b;
	string s;
	cin>>s;
	if(s[a]=='-')
	{
		int i,flag = 0;
		for(i = 0; i<s.length(); i++)
		{
			if(i==a) continue;
			if(s[i]>'9' || s[i]<'0') flag = 1;
		}
		if(flag) cout<<"No"<<endl;
		else cout<<"Yes"<<endl;
	}
	else cout<<"No"<<endl;
	return 0;
}