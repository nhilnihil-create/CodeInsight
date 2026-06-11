///Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>

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

const ll inf=1e17;
const int mod=1e9+7;
const int M=100005;

 main()

{
    fast
    int a,b,q;
    cin>>a>>b>>q;
    set<int>s,t;
    f(i,1,a)
    {
        int x;
        cin>>x;
        s.insert(x);
    }
    f(i,1,b)
    {
        int x;
        cin>>x;
        t.insert(x);
    }
    f(i,1,q)
    {
        int x;
        cin>>x;
        int lft_s,rgt_s,lft_t,rgt_t;
        set<int>::iterator lo,hi;

        hi=s.lower_bound(x);
        if(hi!=s.end())rgt_s=*hi;
        else rgt_s=inf;
        hi=t.lower_bound(x);
        if(hi!=t.end())rgt_t=*hi;
        else rgt_t=inf;

        lo=s.upper_bound(x);
        if(lo==s.begin())lft_s=-inf;
        else {lo--;lft_s=*lo;}
        lo=t.upper_bound(x);
        if(lo==t.begin())lft_t=-inf;
        else {lo--;lft_t=*lo;}
        int cost,ses=inf;
        cost=max(rgt_t,rgt_s)-x;ses=min(ses,cost);
        cost=x-min(lft_t,lft_s);ses=min(ses,cost);
        cost=(rgt_s-x)+(rgt_s-lft_t);ses=min(ses,cost);
        cost=(rgt_t-x)+(rgt_t-lft_s);ses=min(ses,cost);
        cost=(x-lft_t)+(rgt_s-lft_t);ses=min(ses,cost);
        cost=(x-lft_s)+(rgt_t-lft_s);ses=min(ses,cost);
        cout<<ses<<endl;
    }
    return 0;

}



































