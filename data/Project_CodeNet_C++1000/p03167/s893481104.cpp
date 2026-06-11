/***
بسم الله الرحمن الرحيم
اللهم ما صلّ على سيدنا محمد
اذكر الله
واتقوا يوما ترجعون فيه إلى الله ثم توفى كل نفس ما كسبت وهم لا يظلمون
****/

#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define shalaby ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);cerr.tie(0);

using namespace std;

inline int D()
{
    int t;
    scanf("%d",&t);
    return t;
}
inline ll llD()
{
    ll t;
    scanf("%lld",&t);
    return t;
}

const ll OO=-1e18;
int xt[4]= {1,0,0,-1};
int yt[4]= {0,1,-1,0};
////////////////////////////////////////////////////////////////////////////////////

const int N = 1e6+1;



ll mem[1005][1005],n,m,mod=1e9+7;
bool valid(int x,int y)
{
    return x>-1 && y>-1 && x<n && y<m;
}
void init()
{
    memset(mem,-1,sizeof mem);
}
char grid[1009][1009];
ll solve(int i=0,int j=0)
{
  ///  cout<<i<<" "<<j<<endl;
    if(!valid(i,j)|| grid[i][j]=='#')
        return 0;
    if(i==n-1 && j==m-1 && grid[i][j]=='.')
    {
    return 1;
    }
    ll &ret=mem[i][j];
    if(~ret)return ret%mod;

   ret=((solve(i+1,j)%mod)+(solve(i,j+1)%mod))%mod;
   return ret%mod;
}
int main()
{
int T=1;
///T=D();

while(T-->0)
{
    init();
cin>>n>>m;
for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
    cin>>grid[i][j];
cout<<solve();

}

}
