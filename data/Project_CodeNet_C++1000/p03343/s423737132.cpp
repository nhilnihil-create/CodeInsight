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
const int M=2005;
map<int,vector<int> >adj;
int n,k,q;
int vis[M];
int a[M];
set<int>s[M];
int home[M];
 main()

{
    fast
    cin>>n>>k>>q;
    f(i,1,n)
    {
        cin>>a[i];
        adj[a[i]].pb(i);
    }
    int ses=inf;
    vis[n+1]=1;
    adj[0].pb(0);
    for(auto tmp:adj)
    {
        vector<int>idx=tmp.si;
        int x=tmp.fi;
        for(auto id:idx)
        {
            vis[id]=1;
        }
        int cur=0;
        s[cur].clear();
        priority_queue< pi , vector<pi> , greater<pi> > pq;
        f(i,1,n+1)
        {
            if(vis[i])
            {
                if(s[cur].size()!=0)
                {
                    cur++;
                    s[cur].clear();
                }
            }
            else
            {
                s[cur].insert(i);
                home[i]=cur;
                pq.push(mp(a[i],i));
            }
        }
        int tq=q;
        int last=-1;
        int fst;
        while(!pq.empty())
        {
            int z=pq.top().fi;
            int ii=pq.top().si;
            //cout<<z<<" "<<ii<<endl;
            ii=home[ii];
            pq.pop();
            if(s[ii].size()<k)continue;
            s[ii].erase(s[ii].begin());
            tq--;
            if(last==-1)fst=z;
            last=z;
            if(tq==0)break;
        }
       // cout<<fst<<" # "<<last<<endl;
        if(tq==0)
        {
            ses=min(ses,last-fst);
        }
    }
    cout<<ses<<endl;
    return 0;
}

































