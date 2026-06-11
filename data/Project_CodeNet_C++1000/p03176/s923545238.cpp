#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5+20;

ll h[N],a[N],tr[N];
ll f[N];
ll n;
ll lowbit(ll x)
{
	return x&(-x);
}

void add(ll x,ll y)
{
	for(int i=x;i<=n;i+=lowbit(i))	tr[i]=max(tr[i],y);
}

ll query(ll x)
{
	ll ans=0;
	for( int i=x;i>=1;i-=lowbit(i))	
	ans=max(tr[i],ans);
	return ans;
}

int main()
{
	std::ios::sync_with_stdio(false);

	cin>>n;
	for(int i=1;i<=n;i++)	cin>>h[i];
	for(int i=1;i<=n;i++)	cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		f[i]=query(h[i])+a[i];
		add(h[i],f[i]);	
	}
	cout<<query(n)<<endl;

}