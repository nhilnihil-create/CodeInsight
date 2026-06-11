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
	string s,t;
	cin>>s>>t;
	sort(s.begin(),s.end());
	sort(t.begin(),t.end());
	reverse(t.begin(),t.end());
	if(s<t)
		cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}