#include<bits/stdc++.h>
#define MOD 1000000007
#define IO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define forf(i,a,b) for(i=a;i<b;i++)
#define forr(i,a,b) for(i=a;i>b;i--)
#define mp make_pair
#define f first
#define s second
#define pb(x) push_back(x)
typedef  long long  int ll;
typedef std::vector<ll> vi;

#define input(vec,a,b) for(ll i =a;i<b;i++) cin>>vec[i]
#define print(vec,a,b) for(ll i=a;i<b;i++) cout<<vec[i]<<" " ;cout<<endl;
#define all(a) a.begin(),a.end()
using namespace std;
vector<ll> v[100000];
ll p[100000];
bool t[100000];
ll dfs (ll q)
{
         ll val=0;
         for(auto y: v[q])
         {
                  if(t[y]==0)
                  val = max(val,dfs(y)+1);
                  else
                  val=max(val,p[y]+1);
                  
         }
         p[q]=val;
         t[q]=1;
         return val;
}

void solve(){
        ll n,m,i,j,x,y,ma=0;
        cin>>n>>m;
        for(i=0;i<m;i++)
        {
                 cin>>x>>y;
                 x--;y--;
                 v[x].pb(y);
        }
        dfs(0);
        for(i=0;i<n;i++)
        {
                 if(t[i]==0)
                 dfs(i);
                 
                 ma=max(ma,p[i]);
        }
        cout<<ma<<endl;
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