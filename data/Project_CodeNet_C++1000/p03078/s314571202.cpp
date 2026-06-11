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
int x,y,z,k,tmp;
vector<int>a,b,c,yo,ses;
bool chk(int val)
{
    int cur=0,cnt=0;
    for(auto p:yo)
    {
        int nw=val-p;
        while(c[cur]<nw && cur<z-1)
        {
            cur++;
        }
        if(c[cur]>=nw)
        {
           cnt+=(z-cur);
        }
    }
    if(cnt>=k)return true;
    else return false;
}
void work(int val)
{
    int cur=0;
    for(auto p:yo)
    {
         int nw=val-p;
        while(c[cur]<nw && cur<z-1)
        {
            cur++;
        }
        if(c[cur]>=nw)
        {
           for(int i=cur;i<z;i++)
           {
              ses.pb(p+c[i]);
           }
        }
    }
    int sz=ses.size();
    int baki=k-sz;
    while(baki--)
    {
        ses.pb(val-1);
    }
}
 main()

{
    fast
    cin>>x>>y>>z>>k;
    f(i,1,x)
    {
        cin>>tmp;a.pb(tmp);
    }
    f(i,1,y)
    {
        cin>>tmp;b.pb(tmp);
    }
    f(i,1,z)
    {
        cin>>tmp;c.pb(tmp);
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    sort(c.begin(),c.end());
    f(i,0,x-1)
    {
        f(j,0,y-1)
        {
            yo.pb(a[i]+b[j]);
        }
    }
    sort(yo.rbegin(),yo.rend());
    int lo=0,hi=30000000000;
    while(hi>lo)
    {
        int mid=(lo+hi+1)>>1;
        if(chk(mid))
        {
            lo=mid;
        }
        else
        {
            hi=mid-1;
        }
    }
    work(lo+1);
    sort(ses.rbegin(),ses.rend());
    for(auto x:ses)
    {
        cout<<x<<"\n";
    }
    return 0;

}



































