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
#define node(a,b,c)   mp(mp(a,b),c)

using namespace std;

const ll inf=1e18;
const int mod=1e9+7;
const int M=100005;
 main()

{
    fast
    int x;
    cin>>x;
    if(x==2)
    {
        cout<<"2 2"<<endl;
        cout<<"1 2 0"<<endl;
        cout<<"1 2 1"<<endl;
        return 0;
    }
    x--;
    int cur=0;
    while(1)
    {
        int val=(1LL<<(cur+1));
        if(val<=x)cur++;
        else break;
    }
    vector<pair<pi,int>>vec;
    f(i,1,cur)
    {
        vec.pb(node(i,i+1,0));
        int val=(1LL<<(i-1));
        vec.pb(node(i,i+1,val));
    }
    int now=(1LL<<cur);
    int baki=x-(now-1);
    int n=cur+1;
    while(1)
    {
        for(int i=n-1;i>=1;i--)
        {
            int rgt=now+(1LL<<(i-1))-1;
            if(rgt<=x)
            {
               vec.pb(node(i,n,now));
               now=rgt+1;
               break;
            }
        }
        if(now>x)break;
    }
    cout<<cur+1<<" "<<vec.size()<<endl;
    for(auto z:vec)
    {
        cout<<z.fi.fi<<" "<<z.fi.si<<" "<<z.si<<endl;
    }
    return 0;

}



































