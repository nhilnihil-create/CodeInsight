///Bismillahir Rahmanir Rahim
#include<bits/stdc++.h>

#define                           int                         long long
#define                           fi                          first
#define                           si                          second
#define                           mp                          make_pair
#define                           pb                          push_back
#define                           pi                          pair<int,int>
#define                           f(i,l,r)                    for(int i=l;i<=r;i++)
#define                           rf(i,r,l)                   for(int i=r;i>=l;i--)
#define                           done(i)                     cout<<"done = "<<i<<endl;
#define                           fast                        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);




using namespace std;

const int inf=1e18;
const int mod=1e9+7;
const int M=200009;

inline int bigmod(int B,int P){int R=1;while(P>0){if(P&1){R=(R*B)%mod;}P>>=1;B=(B*B)%mod;}return R;}
inline int ad(int x,int y){int ret=(x%mod+y%mod)%mod;if(ret<0){ret+=mod,ret=ret%mod;}return ret;}
inline int sub(int x,int y){int ret=((x%mod)-(y%mod)+mod)%mod;if(ret<0){ret+=mod,ret=ret%mod;}return ret;}
inline int gun(int x,int y){int ret=((x%mod)*(y%mod))%mod;if(ret<0){ret+=mod,ret=ret%mod;}return ret;}

int c[M+3];
int dp[M+4];
int nxt[M+4];
int last[M+3];
 main()

{
    fast
    int n;
    cin>>n;
    memset(last,-1,sizeof last);
    f(i,1,n)cin>>c[i];
    rf(i,n,1)
    {
        nxt[i]=last[c[i]];
        //cout<<nxt[i]<<" ";
        last[c[i]]=i;
    }
   // cout<<endl;
    dp[n]=1;
    rf(i,n-1,1)
    {
        if(nxt[i]==-1)
        {
            dp[i]=dp[i+1];
        }
        else if(nxt[i]==(i+1))
        {
            dp[i]=dp[i+1];
        }
        else
        {
            dp[i]=ad(dp[i+1],dp[nxt[i]]);
        }
    }
    cout<<dp[1]<<endl;
    return 0;

}











