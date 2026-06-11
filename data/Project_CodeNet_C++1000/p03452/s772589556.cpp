
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define endl "\n"
#define se second
#define ls( s) (s&(-s))
#define ll long long
#define inf 0x3f3f3f3f
const int N = 200030;
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
const ll mod =    998244353;
vector<pair<int,int> > g[N];
bool bo[N];
int dist[N],n,m;
bool ans;
void dfs(int idx,int tot)
{
	if(bo[idx])
	{
		if(dist[idx]!=tot)
		ans=true;
		return ;
	}
	bo[idx]=true;
	dist[idx]=tot;
	for(auto &i: g[idx] ) dfs(i.fi,tot+i.se);
}
int main()
{
	ios_base::sync_with_stdio(false);
	    cin.tie(NULL);
  cin>>n>>m;
  for(int i=0;i<m;i++)
  {
  	int x,y,z;
  	cin>>x>>y>>z;
  	g[x].emplace_back(y,z);
  	g[y].emplace_back(x,-z);
  }
  for(int i=1;i<=n;i++)
  {
  	if(!bo[i])
  	{

		dfs(i,0);
	  }
  }
  if(ans)
  cout<<"No";
  else
  cout<<"Yes";
}
