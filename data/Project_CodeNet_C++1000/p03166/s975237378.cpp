#include<bits/stdc++.h>

typedef   long long  int ll;
typedef  long double ld;
typedef std::vector<ll> vi;
typedef std::vector<std::vector<ll> > vv;

#define MOD 1000000007
#define IO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define fo(i,a,b) for(i=a;i<b;i++)
#define mp make_pair
#define pb(x) push_back(x)
#define fi first
#define se second
#define print(vec,a,b) for(ll i=a;i<b;i++) cout<<vec[i]<<" ";cout<<endl;
#define all(a) a.begin(),a.end()
#define input(vec,a,b) for(ll i = a;i<b;i++) cin>>vec[i];
#define ms(a,val) memset(a,val,sizeof(a))
using namespace std;

const int N = 1e5 + 5;
vi adj[N];
ll path = 0;
bool vis[N];
stack<ll> arr;
void top_sort(ll u)
{
    vis[u] = true;
    //cout<<"dfs at"<<u<<endl;
    
    for(int to : adj[u])
    {
		
		if(!vis[to])
			top_sort(to);
	}
	//cout<<u<<" has been pushed"<<endl;
	arr.push(u);

	
}
void solve(){
            ll i,j,n,m;
           cin>>n>>m;
           fo(i,0,m)
           {
			   ll a,b;
			   cin>>a>>b;
			   adj[a].pb(b);
		   }
		   for(i = 1;i<=n;i++)
		   {
			   if(!vis[i])
			   top_sort(i);
		   }
		   vi ord;
		   while(!arr.empty())
		   {
			   ord.pb(arr.top());
			   arr.pop();
		   }
		   //print(ord,0,ord.size());
		   ms(vis,0);
		   ll dis[n+1] ={0}; 
		   for(auto it : ord)
		   {
			   for(auto to : adj[it])
			   {
				   //cout<<it<<" "<<to<<endl;
				   dis[to] = max(dis[to],dis[it]+ 1);
			   }
			     
			}
			//print(dis,1,n+1);
			cout<<*max_element(dis+1,dis+n+1)<<endl;
		   
		   
            
						            









}

int main()
{
    IO;
      ll t=1;
      //cin>>t;


      while(t--)
      {

          solve();
      }
    return 0;
}

