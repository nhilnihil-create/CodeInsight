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
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a+b==c+d) cout<<"Balanced"<<endl;
	else if(a+b>c+d) cout<<"Left"<<endl;
	else cout<<"Right"<<endl;
	return 0;
}