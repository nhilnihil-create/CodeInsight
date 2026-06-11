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
int a[55],mn,mx,mxid,mnid;
 main()

{
    fast
    int n;
    cin>>n;
    f(i,1,n)
    {
        cin>>a[i];
        if(i==1)mx=a[i],mn=a[i];
        mx=max(mx,a[i]);
        mn=min(mn,a[i]);
    }
    f(i,1,n)
    {
        if(a[i]==mx)mxid=i;
        if(a[i]==mn)mnid=i;
    }
    vector<pi>vec;
    if(mx+mn>=0)
    {
       f(i,1,n)
       {
           if(i!=mxid)vec.pb(mp(mxid,i));
       }
       f(i,1,n-1)
       {
           vec.pb(mp(i,i+1));
       }
    }
    else
    {
         f(i,1,n)
         {
             if(i!=mnid)vec.pb(mp(mnid,i));
         }
         rf(i,n,2)
         {
             vec.pb(mp(i,i-1));
         }
    }
    cout<<vec.size()<<endl;
    for(auto x:vec)
    {
        cout<<x.fi<<" "<<x.si<<endl;
    }
    return 0;

}



































