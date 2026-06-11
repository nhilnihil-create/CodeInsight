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

int len[9],n;
inline int Ocost(int x,int gol)
{
    int ret=0;
    int one=__builtin_popcount(x);
    ret=(one-1)*10;
    int sum=0;
    f(i,0,n-1)
    {
        if(x & (1<<i))
        {
           sum+=len[i];
        }
    }
    int gap=abs(gol-sum);
    ret+=gap;
    return ret;

}
bitset<5>chk;
inline pi yo(int x,int g1,int g2)
{
    int nx=0,ny=0;
    pi ret;
    ll mn=inf;
    for(int i=x;i;i=(i-1)&x)
    {
        nx=0,ny=0;
        for(int k=0;k<n;k++)
        {
             if(!(x & (1<<k)))continue;
            if(i & (1<<k))nx+=(1<<k);
            else ny+=(1<<k);
        }
        if(__builtin_popcount(nx)<1 || __builtin_popcount(ny)<1)continue;
        pi tmp;
        tmp.fi=Ocost(nx,g1);
        tmp.si=Ocost(ny,g2);
        int val=tmp.fi+tmp.si;
        if(val<=mn)
        {
            mn=val;
            ret=tmp;
        }
    }
    return ret;
}
 main()

{

    int a,b,c;
    cin>>n>>a>>b>>c;
    f(i,0,n-1)cin>>len[i];
    int mx=(1<<n)-1;
    ll ses=inf;
    f(i,0,mx)
    {
       int one=__builtin_popcount(i);
       if(one<3)continue;
       for(int j=i;j;j=(j-1)&i)
       {
            int p=0,q=0;
            for(int k=0;k<n;k++)
            {
                if((i & (1<<k))==0)continue;
                if((j & (1<<k)))
                {
                     p+=(1<<k);
                }
                else q+=(1<<k);
            }
            if(__builtin_popcount(p)<1 || __builtin_popcount(q)<2)continue;
           ll x=Ocost(p,a);
           pi tmp=yo(q,b,c);
           ll y=tmp.fi;
           ll z=tmp.si;
           ses=min(ses,x+y+z);

       }
    }
    cout<<ses<<endl;
    return 0;
}
