///Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#pragma warning(disable:4786)
#pragma warning(disable:4996)

#define                           fi                          first
#define                           si                          second
#define                           mp                          make_pair
#define                           pb                          push_back
#define                           pi                          pair<int,int>
#define                           clr(x)                      memset(x,0,sizeof(x));
#define                           f(i,l,r)                    for(int i=l;i<=r;i++)
#define                           rf(i,r,l)                   for(int i=r;i>=l;i--)
#define                           done(i)                     cout<<"done = "<<i<<endl;
#define                           fast                        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);




using namespace std;


const int mod=1e9+7;
const int M=100009;

inline int bigmod(int B,int P){int R=1;while(P>0){if(P&1){R=(R*B)%mod;}P>>=1;B=(B*B)%mod;}return R;}
inline int ad(int x,int y){int ret=(x%mod+y%mod)%mod;if(ret<0){ret+=mod,ret=ret%mod;}return ret;}
inline int sub(int x,int y){int ret=((x%mod)-(y%mod)+mod)%mod;if(ret<0){ret+=mod,ret=ret%mod;}return ret;}
inline int gun(int x,int y){int ret=((x%mod)*(y%mod))%mod;if(ret<0){ret+=mod,ret=ret%mod;}return ret;}


 main()

{
    //fast
    int n;
    scanf("%d",&n);
    int a[n+4];
    vector<int>alive;
    f(i,1,n)scanf("%d",&a[i]),alive.pb(i);
    int two=(1<<30);
    int ses=0;
    int vis[n+4];clr(vis);
    for(int j=30;j>=1;j--)
    {

         unordered_map<int,vector<int>>cnt;
         for(auto i:alive)
         {
             if(vis[i]==1)continue;
             if(cnt[a[i]].size())
             {
                 int id=cnt[a[i]].back();
                 cnt[a[i]].pop_back();
                 vis[id]=1;
                 vis[i]=1;
                 ses++;
                // cout<<i<<" "<<id<<endl;
                 continue;
             }
             if(two<a[i])continue;
             int val=two-a[i];
             cnt[val].pb(i);
         }
         two=two/2;
         if(two<=1)break;
         vector<int>tmp;
         for(auto i:alive)
         {
             if(vis[i]==0)
             {
                 tmp.pb(i);
             }
         }
         alive=tmp;

    }
    printf("%d\n",ses);
    return 0;

}



































