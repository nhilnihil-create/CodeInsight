#include<bits/stdc++.h>
using namespace std;
             
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll,ll> Pi;
typedef map<ll,ll> mi;
             
template<class T> T nrem(T x,T y){return ((x%y)+y)%y;}
             
#define For(i,a,n) for(int i=a;i<n;++i)
#define For0(i,n) for(int i=0;i<n;++i)
#define For1(i,n) for(int i=1;i<=n;++i)
#define Forl0(i,n) for(ll i=0;i<n;++i)
#define Forl1(i,n) for(ll i=1;i<=n;++i)
#define fi freopen("input.txt","r",stdin);
#define fo freopen("output.txt","w",stdout);
#define pb push_back
#define mp make_pair
#define endl "\n"
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define cs 200005
#define pi acos(-1)
#define INF (int)INFINITY
void in()
    {
         #ifndef ONLINE_JUDGE
         freopen("input.txt", "r", stdin);
         freopen("output.txt", "w", stdout);
        #endif
    }

int a[505][505];
int vis[505][505];

int main()
{  
    IOS
    in();
    
    int h,w;
    cin>>h>>w;
    
    vector<pair<pair<int,int>,pair<int,int>>>ans;

    For1(i,h)
    For1(j,w)    
    cin>>a[i][j];


    For1(i,h)
    For1(j,w)
    {
       if(a[i][j]%2==1&&vis[i][j]==0)
       {
          vis[i][j]=1;
          a[i][j]-=1;

          if(a[i-1][j]%2&&i-1>=1)
          {
              a[i-1][j]+=1;
              ans.pb(mp(mp(i,j),mp(i-1,j)));
          }
          else if(a[i][j-1]%2&&j-1>=1)
          {
             a[i][j-1]+=1;
              ans.pb(mp(mp(i,j),mp(i,j-1)));    
          }
          
          else if(a[i+1][j]%2&&i+1<=h)
          {
             a[i+1][j]+=1;
              ans.pb(mp(mp(i,j),mp(i+1,j)));    
          }
          
          else if(a[i][j+1]%2&&j+1<=w)
          {
             a[i][j+1]+=1;
              ans.pb(mp(mp(i,j),mp(i,j+1)));    
          }
          else if(i+1<=h)
          {
               a[i+1][j]+=1;
              ans.pb(mp(mp(i,j),mp(i+1,j)));   
          }
          else if(j+1<=w)
          {
              a[i][j+1]+=1;
              ans.pb(mp(mp(i,j),mp(i,j+1)));  
          }
       }   
    }
    
   cout<<ans.size()<<endl;
    For0(i,ans.size())
    cout<<ans[i].first.first<<" "<<ans[i].first.second<<" "<<ans[i].second.first<<" "<<ans[i].second.second<<endl;
}