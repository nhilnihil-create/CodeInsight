///Bismillahir Rahmanir Rahim
#include "bits/stdc++.h"

#define                           ll                          long long
#define                           int                         ll
#define                           fi                          first
#define                           si                          second
#define                           mp                          make_pair
#define                           pb                          push_back
#define                           pi                          pair<ll,ll>
#define                           clr(x)                      memset(x,0,sizeof(x));
#define                           f(i,l,r)                    for(int i=l;i<=r;i++)
#define                           rf(i,r,l)                   for(int i=r;i>=l;i--)
#define                           done(i)                     cout<<"done = "<<i<<endl;
#define                           show(x,y)                   cout<<x<<" : ";for(auto z:y)cout<<z<<" ";cout<<endl;
#define                           fast                        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

const ll inf=1e18;
const int mod=1e9+7;
const int M=100005;
int par[M];
int fnd(int x)
{
    if(x==par[x])return x;
    return par[x]=fnd(par[x]);
}
void tie(int x,int y)
{
    int fx=fnd(x);
    int fy=fnd(y);
    if(fx==fy)return ;
    par[fy]=fx;
}
 main()

{
    fast
    int n,m;
    cin>>n>>m;
    f(i,1,n)par[i]=i;
    f(i,1,m)
    {
        int u,v,w;
        cin>>u>>v>>w;
        tie(u,v);
    }
    set<int>s;
    f(i,1,n)
    {
        s.insert(fnd(i));
    }
    cout<<s.size()<<endl;
    return 0;

}



































