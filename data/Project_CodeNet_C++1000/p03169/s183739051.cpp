#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

db dp[301][301][301];

db fun(int x,int y,int z,int &n)
{
    if(x==0 && y==0 && z==0)return 0;
    if (x<0 || y<0 ||z<0)return 0;
    if(dp[x][y][z]>-0.9)return dp[x][y][z];
    db exp=n+x*fun(x-1,y,z,n)+y*fun(x+1,y-1,z,n)+z*fun(x,y+1,z-1,n);
    return dp[x][y][z]=exp/(x+y+z);
}
void solve()
{
    int n;
    cin>>n;
    int cnt[3]={0,0,0};
    for(int i=0; i<n; i++){
        int s;cin>>s;
        cnt[s-1]+=1;
    }
    memset(dp,-1,sizeof dp);
    fun(cnt[0],cnt[1],cnt[2],n);
    cout<<fixed<<setprecision(10)<<dp[cnt[0]][cnt[1]][cnt[2]];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    t=1;
    while(t--){
        solve();
        cout<<endl;
    }
}
