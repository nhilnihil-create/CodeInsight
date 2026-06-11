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
const int M=1002;
int n,m;
int x[M],y[M],z[M];
int dp[M][M];
int solve(int pos,int baki,int a,int b,int c)
{
    if(pos>n)
    {
        if(baki==0)return 0;
        else return -inf;
    }
    int &ret=dp[pos][baki];
    if(ret!=(-1))return ret;
    ret=solve(pos+1,baki,a,b,c);
    if(baki==0)return ret;
    int nx=x[pos]*a,ny=y[pos]*b,nz=z[pos]*c;
    int cost=nx+ny+nz;
    ret=max(ret,cost+solve(pos+1,baki-1,a,b,c));
    return ret;
}
 main()

{
    fast
    cin>>n>>m;
    f(i,1,n)cin>>x[i]>>y[i]>>z[i];
    int ses=-inf;
    f(i,-1,1)f(j,-1,1)f(k,-1,1)
    {
        if(i==0 || j==0 || k==0)continue;
        memset(dp,-1,sizeof dp);
        ses=max(ses,solve(1,m,i,j,k));
    }
    cout<<ses<<endl;
    return 0;

}



































