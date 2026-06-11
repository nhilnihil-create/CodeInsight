#include<bits/stdc++.h>
#define ll long long int
#define ar array
#define pb push_back
#define forf(i,a,b) for(i = a; i< b; i++)
#define forb(i,a,b) for(i = b; i>=a; i--)
using namespace std;
const int mod = 1e9+7;
ll power(ll a,ll b){ll r=1;for(;b;b>>=1){if(b&1)r=r*a%mod;a=a*a%mod;}return r;}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int a,b,c;
	cin>>a>>b>>c;
	if(a+b>=c) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}