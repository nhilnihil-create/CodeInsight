#include<bits/stdc++.h>
using namespace std;
using ll=long long;

struct Union_Find
{
	ll ans;
    vector <ll> parent;
	vector<ll> sz;
    Union_Find(ll N) : parent(N)
    {
		sz.resize(N,1);
        for(ll i = 0; i < N; i++) parent[i] = i;
		ans=N*(N-1)/2;
    }
    ll root(ll n)
    {
        if (parent[n]==n) return n;
        else
        {
            return root(parent[n]);
        }
    }

    void unite(ll i,ll j)
    {
        ll rx,ry;
        rx=root(i);
        ry=root(j);
        if (rx==ry) return;
        else
        {
            ll k;
            if (rx<ry)
            {
				ans-=sz[rx]*sz[ry];
				sz[rx]+=sz[ry];
				sz[ry]=0;
                parent[ry]=rx;
                return;
            }
            else
            {
				ans-=sz[rx]*sz[ry];
				sz[ry]+=sz[rx];
				sz[rx]=0;
                parent[rx]=ry;
                return;
            }
        }
    }
    bool same(ll i, ll j)
    {
        if (root(i)==root(j)) return true;
        else return false;
    }
};

int main()
{
	ll n,m; cin>> n >> m;
	vector<pair<ll,ll>> edge(m);
	ll u,v;
	for (ll i=0;i<m;i++)
	{
		cin >> u >>v;
		u--;v--;
		edge[i].first=u;
		edge[i].second=v;
	}
	Union_Find solve(n);
	vector<ll> ans(m);
	for (ll i=m-1;i>=0;i--)
	{
		ans[i]=solve.ans;
		solve.unite(edge[i].first,edge[i].second);
	}
	for (ll i=0;i<m;i++) cout << ans[i] << endl;
	return 0;
}


