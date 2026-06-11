///Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>

#define                           int                         long long
#define                           fi                          first
#define                           si                          second
#define                           mp                          make_pair
#define                           pb                          push_back
#define                           pi                          pair<int,int>
#define                           clr(x)                      memset(x,0,sizeof(x));
#define                           f(i,l,r)                    for(int i=l;i<=r;i++)
#define                           rf(i,r,l)                   for(int i=r;i>=l;i--)
#define                           done(i)                     cout<<"done = "<<i<<endl;
#define                           fast                        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);




using namespace std;

const int inf=1e18;
const int mod=1e9+7;
const int M=100009;

inline int bigmod(int B,int P){int R=1;while(P>0){if(P&1){R=(R*B)%mod;}P>>=1;B=(B*B)%mod;}return R;}
inline int ad(int x,int y){int ret=(x%mod+y%mod)%mod;if(ret<0){ret+=mod,ret=ret%mod;}return ret;}
inline int sub(int x,int y){int ret=((x%mod)-(y%mod)+mod)%mod;if(ret<0){ret+=mod,ret=ret%mod;}return ret;}
inline int gun(int x,int y){int ret=((x%mod)*(y%mod))%mod;if(ret<0){ret+=mod,ret=ret%mod;}return ret;}


 main()

{
    fast
    int n,m;
    string s,t;
    cin>>n>>m;
    cin>>s>>t;
    int lcm=(n*m)/__gcd(n,m);
    map<int,int>no;
    f(i,0,n-1)
    {
        int val=(i*lcm)/n;
        no[val]=i;
    }
    f(i,0,m-1)
    {
        int val=(i*lcm)/m;
        if(no.count(val)==0)continue;
        int x=i;
        int y=no[val];
        if(s[y]!=t[x])
        {
            cout<<"-1"<<endl;
            return 0;
        }
    }
    cout<<lcm<<endl;
    return 0;

}



































