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
map<int,vector<int> >yo;
map<int,int>vis;
vector<pi>vec;
map<int,vector<int> >nisi;
set<int>types;
 main()

{
    fast
    int n,k;
    cin>>n>>k;
    f(i,1,n)
    {
        int t,d;
        cin>>t>>d;
        yo[t].pb(d);
        vec.pb(mp(d,t));
        types.insert(t);
    }
    for(auto x:yo)
    {
        sort(yo[x.fi].begin(),yo[x.fi].end());
    }
    int ses=0;
    sort(vec.rbegin(),vec.rend());
    for(int i=0;i<k;i++)
    {
        int typ=vec[i].si;
        int val=vec[i].fi;
        ses+=val;
        nisi[typ].pb(val);
        vis[typ]=1;
    }
    vector<int>fre,nw;
    int sz=nisi.size();
    ses+=(sz*sz);
    int cost=ses;
    for(auto x:nisi)
    {

        sort(nisi[x.fi].begin(),nisi[x.fi].end());
        nisi[x.fi].pop_back();
        for(auto y:nisi[x.fi])
        {
            fre.pb(y);
        }
    }
    for(auto t:types)
    {
        if(vis.count(t)==0)
        {
            nw.pb(yo[t].back());
        }
    }
    sort(fre.rbegin(),fre.rend());
    sort(nw.rbegin(),nw.rend());
    for(auto x:nw)
    {
        if(fre.size()==0)break;
        ses-=(sz*sz);
        ses-=fre.back();
        fre.pop_back();
        ses+=x;
        sz++;
        ses+=(sz*sz);
        cost=max(cost,ses);
    }
    cout<<cost<<endl;
    return 0;

}




































