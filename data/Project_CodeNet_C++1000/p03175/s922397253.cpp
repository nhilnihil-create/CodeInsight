#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 200000
#define mod1 1000000007
#define mod2 1000000009
#define mod3 998244353
#define endl '\n'
#define IO ios_base::sync_with_stdio(false);cin.tie(NULL);
vector <ll> black(N+5,1),white(N+5,1);
vector <ll> G[N+5];
void dfs(ll node,ll parent)
{
	for(auto child:G[node])
	{
		if(child!=parent)
			dfs(child,node);
	}
	for(auto child:G[node])
	{
		if(child==parent)
			continue;
		black[node] = (black[node] * (white[child]))%mod1;
		white[node] = (white[node] * (black[child] 
			+ white[child]))%mod1;
	}
	return;
}
int main()
{
    IO
	clock_t begin = clock();
    ll n;
    cin>>n;
    for(ll i=1;i<n;i++)
    {
    	ll p,q;
    	cin>>p>>q;
    	G[p].push_back(q);
    	G[q].push_back(p);
    }
    dfs(1,0);
    cout<<(black[1] + white[1])%mod1<<endl;
    // cout<<double(clock() - begin)/CLOCKS_PER_SEC<<endl;
    return 0;
}