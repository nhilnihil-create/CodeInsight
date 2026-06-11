///Bismillahir Rahmanir Rahim
#include "bits/stdc++.h"

#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#pragma warning(disable:4786)
#pragma warning(disable:4996)

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
#define                           show(x,y)                   cout<<x<<" : ";for(auto z:y)cout<<z<<" ";cout<<endl;
#define                           fast                        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;

const ll inf=1e18;
const int mod=1e9+7;
const int M=100005;
int a[M],b[M];
bitset<35>bt,kbt,z;
vector<int>vec;
 main()

{
    int n,k;
    scanf("%d%d",&n,&k);
    f(i,1,n)
    {
       scanf("%d%d",&a[i],&b[i]);
       vec.pb(i);
    }
    kbt=k;
    ll ses=0;
    for(int j=32;j>=0;j--)
    {

        if(kbt[j]==0)
        {
            vector<int>nw;
            for(auto x:vec)
            {
                z=a[x];
                if(z[j]==0)nw.pb(x);
            }
            vec=nw;
        }
        else
        {

            vector<int>zr,o;
            for(auto x:vec)
            {
                z=a[x];
                if(z[j]==0)zr.pb(x);
                o.pb(x);
            }
           vec=o;
           ll cost=0;
           for(auto x:zr)
           {
               cost+=b[x];
           }
           ses=max(ses,cost);
        }

    }
    ll cost=0;
    for(auto x:vec)
    {
        cost+=b[x];
    }
    ses=max(ses,cost);
    printf("%lld\n",ses);
    return 0;

}



































