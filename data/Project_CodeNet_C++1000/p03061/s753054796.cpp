#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
typedef long long ll;
ll p[maxn], l[maxn], a[maxn];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	p[1]=a[1], l[n]=a[n];
	ll ans=0;
	for(int i=2;i<=n;i++)
	{
		p[i]=__gcd(p[i-1], a[i]);
//		l[n-i+1]=__gcd(l[n-i+2], a[n-i+1]);
	}
	for(int i=n-1;i>=1;i--)
	{
		l[i]=__gcd(l[i+1], a[i]);
	}
	for(int i=2;i<n;i++)
	{
		ans = max(ans, __gcd(p[i-1], l[i+1]));
	}
	cout<<max(ans, max(l[2], p[n-1]))<<endl;
}