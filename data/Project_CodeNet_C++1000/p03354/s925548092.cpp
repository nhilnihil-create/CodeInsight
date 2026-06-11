#include<bits/stdc++.h>
#include<bitset>


using namespace std;

#define M 1000000007
#define pb push_back
#define f first
#define s second
#define rep(i, st, ed) for(int i=st; i<ed; i++)
#define repn(i, st, ed) for(int i=st; i<=ed; i++)
#define repb(i, ed, st) for(int i=ed; i>=st; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;
typedef unsigned long long int llt;
typedef long double ld;

const long double PI  =3.141592653589793238463;
const int N = 1e5 + 10;
const ll INF = 1LL << 60;

template<class T> void chmax(T &a,T b) { if (a<b) a=b;}
template<class T> void chmin(T &a,T b) { if (a>b) a=b;}



// Main Code
int arr[N];
vector<int> g[N];
bool vis[N];
map<int, int> mp;
vector<int> pos, node;
void dfs(int curr, int par)
{
  vis[curr] = 1;
  pos.pb(curr);
  node.pb(arr[curr]);
  for(auto x: g[curr])
    if(!vis[x])
      dfs(x, curr);
}
int main()
{
	int n, m;
	cin>>n>>m;
	repn(i, 1 , n) {
		cin>>arr[i];
		mp[arr[i]] = i;
	}
	rep(i,0 , m)
	{
		int x, y;
		cin>>x>>y;
		g[x].pb(y);
		g[y].pb(x);
	}
	int ans = 0;
	rep(i, 1, n+1)
		if(vis[i] == 0)
		{
			pos.clear(); node.clear();
			dfs(i, -1);
			sort(all(pos));
			for(int x: node)
			{
				auto itr = lower_bound(all(pos), x);
				if(itr == pos.end()) continue; 
				if(*itr == x)
				{ 
					ans++;
					// cout<<x<<" "<<(*itr)<<endl;
				}
			}
		}
	cout<<ans<<endl;
	// cout<<arr[418]<<" "<<arr[922]<<endl;
	// cout<<arr[21]<<endl;
	// cout<<arr[890]<<endl;
}
