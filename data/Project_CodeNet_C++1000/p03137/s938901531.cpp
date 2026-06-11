#include <iostream>
using namespace std; 
typedef long long int ll;
#define rd(t,n) for (int i = 0; i < n; i++)cin>>t[i]
int main() 
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n,m;cin>>n>>m;
	ll t[m];rd(t,m);
	sort(t,t+m);
	ll d[m];d[0]=0;
	for (int i = 1; i < m; i++)d[i]=t[i]-t[i-1];
	sort(d,d+m);
	ll s=0;
	for (int i = 0; i <= m-n; i++)s+=d[i];
	cout<<s; 
}