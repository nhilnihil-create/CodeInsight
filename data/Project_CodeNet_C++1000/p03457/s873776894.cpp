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
	int n;
	cin>>n;
	vector<ar<int,3>> v(n);
	for(int i = 0,j,k,l; i<n; i++)
	{
		cin>>j>>k>>l;
		v[i] = {j,k,l};
	}
	int flag = 1;
	int h = v[0][1]+v[0][2];
	if(v[0][0]!=h)
		if((v[0][0]-h)%2!=0 || v[0][0]<h) flag = 0;
	for(int i = 1; i<n; i++)
	{
		int t = v[i][0]-v[i-1][0];
		int dist = abs(v[i][1]-v[i-1][1])+abs(v[i][2]-v[i-1][2]);
		if(t<dist) flag = 0;
		else if((t-dist)%2!=0) flag = 0;
	}
	if(flag) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}