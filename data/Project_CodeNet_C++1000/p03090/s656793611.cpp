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
const int M=103;

inline int bigmod(int B,int P){int R=1;while(P>0){if(P&1){R=(R*B)%mod;}P>>=1;B=(B*B)%mod;}return R;}
inline int ad(int x,int y){int ret=(x%mod+y%mod)%mod;if(ret<0){ret+=mod,ret=ret%mod;}return ret;}
inline int sub(int x,int y){int ret=((x%mod)-(y%mod)+mod)%mod;if(ret<0){ret+=mod,ret=ret%mod;}return ret;}
inline int gun(int x,int y){int ret=((x%mod)*(y%mod))%mod;if(ret<0){ret+=mod,ret=ret%mod;}return ret;}

int vis[M+2][M+2];

 main()

{
    fast
    int n,flag=0;
    cin>>n;
    if(n%2==1)
    {
        n=n-1;
        flag=1;
    }
    int h=n/2;
    f(i,1,n-1)
    {
        f(j,i+1,n)
        {
            vis[i][j]=1;
        }
    }
    f(i,1,h)
    {
        int x=i;
        int y=n-i+1;
        vis[x][y]=0;
    }
    if(flag==1)
    {
        f(i,1,n)vis[i][n+1]=1,vis[n+1][i]=1;
        n++;
    }
    int cnt=0;
     f(i,1,n-1)
    {
        f(j,i+1,n)
        {
            if(vis[i][j]==1)
            {
                 cnt++;
            }
        }
    }
    cout<<cnt<<endl;
    f(i,1,n-1)
    {
        f(j,i+1,n)
        {
            if(vis[i][j]==1)
            {
                cout<<i<<" "<<j<<endl;
            }
        }
    }
    return 0;

}











