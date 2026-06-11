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


 main()

{
    fast
    int d,g;
    cin>>d>>g;
    g=g/100;
    int p[d+2],c[d+2];
    int id[d+2];
    ll ses=inf;
    f(i,1,d)
    {
        cin>>p[i]>>c[i];
        c[i]=c[i]/100;
        id[i]=i;
    }
    do
    {
        ll sum=g,cnt=0;
        for(int i=1;i<=d;i++)
        {
            int idx=id[i];
            int nd=sum/idx;
            if(sum%idx!=0)nd++;
            if(nd<=p[idx])
            {
                cnt+=nd;
                break;
            }
            else
            {
                cnt+=p[idx];
                sum-=(idx*p[idx]);
                sum-=c[idx];
                if(sum<=0)break;

            }

        }

        ses=min(ses,cnt);

    }while(next_permutation(id+1,id+d+1));
    cout<<ses<<endl;
    return 0;

}



































