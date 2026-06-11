#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e5+5;
pair<ll, ll>p[maxn];
ll par[maxn];
ll ans[maxn];
ll sz[maxn];

ll find(ll x)
{
	return par[x] == x ? x : par[x] = find(par[x]);
}


int n , m;	
	
int main()
{
	cin >> n >> m;
	
	for(int i = 1 ;i <=n ;i++)
	par[i] = i , sz[i] = 1;
	
	for(int i = 0 ;i<m ; i++)
	cin >> p[i].first >>  p[i].second;
	
	ll sum = 1LL *n*(n-1)/2;
	
	for(int i = m - 1 ;i >=0 ;i--)
	{
		ans[i] = sum;
		int x = find(p[i].first);
		int y = find(p[i].second);
		if(x!=y)
		{
			par[y] = x;
			sum -= sz[x]*sz[y];
			sz[x]+=sz[y];
		}
	}
	
	for(int i = 0 ;i<m;i++)
	cout << ans[i]<<endl;

	
	
}