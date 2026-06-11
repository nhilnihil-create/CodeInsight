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

const ll inf=1e18;
const int mod=1e9+7;
const int M=100009;
int prime[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
vector<pi>p;
int n;
pi fnd(int x)
{
    int ret=0;
    pi r;
    r.fi=x;
    while(1)
    {
        ret+=(n/x);
        x=x*r.fi;
        if(x>n)break;
    }
    r.si=ret;
    return r;
}
 main()

{
    fast
    cin>>n;
    for(int i=0;i<25;i++)
    {
        int x=prime[i];
        if(x>n)break;
        pi nw=fnd(x);
        p.pb(nw);
    }
    int ses=0;
    int sz=p.size();
    for(int i=0;i<sz;i++)
    {
        int cnt=p[i].si;
        int x=p[i].fi;
        if(cnt>=74)
        {
            ses++;
        }
    }
    for(int i=0;i<sz;i++)
    {
        for(int j=0;j<sz;j++)
        {
            if(i==j)continue;
            int c1=p[i].si;
            int c2=p[j].si;
            if(c1>=2 && c2>=24)ses++;
            if(c1>=4 && c2>=14)ses++;
        }
    }
    int yo=0;
    for(int i=0;i<sz;i++)
    {
        int cnt=p[i].si;
        if(cnt>=4)yo++;
    }
    f(i,0,sz-1)
    {
        int c=p[i].si;
        if(c>=2)
        {

            int x=yo;
            if(c>=4)x--;
            x=(x*(x-1))/2;
            ses+=x;
        }
    }
    cout<<ses<<endl;
    return 0;

}



































