#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define jizz ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pb push_back
#define F first
#define S second
#define MP make_pair
#define ET cout << "\n"
#define ALL(v) v.begin(),v.end()
#define MEM(i,j) memset(i,j,sizeof i)
#define DB(a,s,e) {for(int i=s;i<e;i++) cout << a[i] << " ";ET;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

bitset<100001> vis;
multiset<pll> s;
vector<pll> v;
pll arr[100001],tarr[100001];
ll w[100001],dp[100001];
vector<ll> child[100001];

void dfs(ll x)
{
	dp[x]=w[x]-1;
	for(ll i:child[x])
		dfs(i),dp[x]+=dp[i];
}

int main()
{jizz
	ll n,x,c=0,t;
	cin >> n;
	for(int i=1;i<=n;++i)
		cin >> x,s.insert(tarr[i]=arr[i]=MP(x,i)),w[i]=1;
	sort(tarr+1,tarr+n+1);
	for(int i=n;i>0;--i)
		if(!vis[tarr[i].S])
		{
			x=tarr[i].S;
			while(1)
			{
				//cout << x << " " << w[x] << " " << arr[x].F << " " << arr[x].F-n+w[x]*2 << "\n";
				auto p=s.lower_bound(MP(arr[x].F-n+w[x]*2,-1));
				if(p==s.end()||p->F!=arr[x].F-n+w[x]*2)
					break;
				//cout << x << " -> " << p->S << "*\n";
				s.erase(s.find(MP(arr[x].F,arr[x].S)));
				//cout << x << " -> " << p->S << "\n";
				vis[x]=1,v.pb(MP(x,p->S)),w[p->S]+=w[x],child[p->S].pb(x),x=p->S;
			}
		}
	if(vis.count()!=n-1) cout << "-1\n";
	else
	{
		for(int i=1;i<=n;++i)
			if(!vis[i]) x=i;
		dfs(x);
		if(dp[x]!=arr[x].F) cout << "-1\n";
		else 
			for(auto i:v)
				cout << i.F << " " << i.S << "\n";
	}
}