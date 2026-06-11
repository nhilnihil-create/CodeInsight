///Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>

#define                           ll                          long long
#define                           fi                          first
#define                           si                          second
#define                           mp                          make_pair
#define                           pb                          push_back
#define                           pi                          pair<ll,ll>
#define                           clr(x)                      memset(x,0,sizeof(x));
#define                           f(i,l,r)                    for(int i=l;i<=r;i++)
#define                           rf(i,r,l)                   for(int i=r;i>=l;i--)
#define                           done(i)                     cout<<"done = "<<i<<endl;
#define                           fast                        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);




using namespace std;

const ll inf=1e18;
const int mod=1e9+7;
const int M=100009;

inline ll bigmod(ll B,ll P){ll R=1;while(P>0){if(P&1){R=(R*B)%mod;}P>>=1;B=(B*B)%mod;}return R;}
inline ll ad(ll x,ll y){ll ret=(x%mod+y%mod)%mod;if(ret<0){ret+=mod,ret=ret%mod;}return ret;}
inline ll sub(ll x,ll y){ll ret=((x%mod)-(y%mod)+mod)%mod;if(ret<0){ret+=mod,ret=ret%mod;}return ret;}
inline ll gun(ll x,ll y){ll ret=((x%mod)*(y%mod))%mod;if(ret<0){ret+=mod,ret=ret%mod;}return ret;}

vector<int>vec[M+6];
 main()

{
    fast
    int n,m;
    cin>>n>>m;
    f(i,1,m)
    {
        int u,v;
        cin>>u>>v;
        vec[u].pb(v);
    }
    priority_queue<int>pq;
    int ses=0;
    for(int i=1;i<=M;i++)
    {
        ll rmn=inf;
        if(!pq.empty())
        {
            rmn=-pq.top();
        }
        if(rmn==i)
        {
            ses++;
            while(!pq.empty())pq.pop();
        }
        for(auto x:vec[i])
        {
            pq.push(-x);
        }
    }
    cout<<ses<<endl;
    return 0;

}



































