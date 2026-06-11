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
const int M=200005;
int n,q;
string s;
int c[M],d[M];
int box[M];
bool chk(int pos)
{
    int rong=box[pos];
    int cur=pos;
    f(i,1,q)
    {
        if(c[i]==box[cur])
        {
            if(d[i]==0)
            {
                cur--;
                if(cur==0)return true;
            }
            else
            {
                cur++;
                if(cur>n)return false;
            }
        }
    }
    return false;
}
bool chk2(int pos)
{
    int rong=box[pos];
    int cur=pos;
    f(i,1,q)
    {
        if(c[i]==box[cur])
        {
            if(d[i]==0)
            {
                cur--;
                if(cur==0)return false;
            }
            else
            {
                cur++;
                if(cur>n)return true;
            }
        }
    }
    return false;
}
 main()

{
    fast
    cin>>n>>q;
    cin>>s;
    f(i,1,n)
    {
        box[i]=s[i-1]-'a';
    }
    f(i,1,q)
    {
        char ch,ch2;
        cin>>ch>>ch2;
        c[i]=ch-'a';
        if(ch2=='R')d[i]=1;
    }
    int lo=1,hi=n;
    while(hi>lo)
    {
        int mid=(lo+hi+1)>>1;
        if(chk(mid))
        {
            lo=mid;
        }
        else hi=mid-1;
    }
    int lft=0,rgt=n+1;
    if(chk(lo))lft=lo;
    lo=1,hi=n;
    while(hi>lo)
    {
        int mid=(lo+hi)>>1;
        if(chk2(mid))
        {
            hi=mid;
        }
        else
        {
            lo=mid+1;
        }
    }
    if(chk2(lo))rgt=lo;
    int ses=lft+(n+1-rgt);
    ses=n-ses;
    cout<<ses<<endl;
    return 0;

}

































