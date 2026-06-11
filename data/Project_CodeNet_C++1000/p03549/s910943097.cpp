#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long int
#define ar array
#define pb push_back
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	ll n, m, i = 1;
	cin>>n>>m;
	int g = pow(2,m);
	int ans = i*(1900*m+(n-m)*100)*g;
	cout<<ans<<endl;
	return 0;
}