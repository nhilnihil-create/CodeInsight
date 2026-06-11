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
	int h,w,d;
	cin>>h>>w>>d;
	int a;
	ar<int,2> co[h*w];
	for(int i = 0; i<h; i++) for(int j = 0; j<w; j++){ cin>>a,--a; co[a] = {i,j};}
	int q;
	cin>>q;
	int v[h*w]={0};
	for(int i = 0; i+d<h*w; i++)
	{
		v[i+d] = abs(co[i+d][0]-co[i][0])+abs(co[i+d][1]-co[i][1])+v[i];
	}
	while(q--)
	{
		int b,c;
		cin>>b>>c;
		--b,--c;
		int ans = v[c]-v[b];
		cout<<ans<<endl;
	}
	return 0;
}