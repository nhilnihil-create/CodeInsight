#include<bits/stdc++.h>
#define ll long long int
#define db long double
#define ull unsigned long long int
#define mp make_pair
#define F first
#define S second
#define pb push_back
#define rep(i,a,b)  for(ll i=a;i<=b;i++)
#define all(a) a.begin(),a.end()
#define Nmax 1000005
#define INF 1000000000
#define MOD 1000000007
#define MAXN 1000005
 
using namespace std;

vector<ll> tree[100005];
ll dpw[100005],dpb[100005];

void dfs(ll node,ll par)
{
	ll black=1,white=1;
	for(auto x:tree[node])
	{
		if(x==par) continue;
		dfs(x,node);
		black*=dpw[x];
		black%=MOD;
		white*=(dpw[x]+dpb[x]);
		white%=MOD;
	}
	dpw[node]=white;
	dpb[node]=black;
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int tests=1;
    // compute();
    // cin>>tests;
    while(tests--)
    {
    	ll i,j,n;
    	cin>>n;
    	rep(i,1,n-1)
    	{
    		ll x,y;
    		cin>>x>>y;
    		tree[x].pb(y);
    		tree[y].pb(x);
    	}
    	dfs(1,0);
    	cout<<(dpb[1]+dpw[1])%MOD;

    }
    	return 0;
    
}