#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define FASTIO cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define loop(i,a,b) for(int i=a; i<b; i++)
#define INF 10000000000099ll
#define mod 1000000007
#define prDouble(x) cout<<fixed<<setprecision(10)<<x

double dp[301][301][301];
double solve(int x, int y, int z, int& n)
{
    if(x<0 || y<0 || z<0) return 0;
    if(x==0 && y==0 && z==0) return 0;
    if(dp[x][y][z] >-0.1) return dp[x][y][z];
    double ans= n+ x*solve(x-1,y,z,n)+ y*solve(x+1,y-1,z,n)+ z*solve(x, y+1, z-1, n);
    return dp[x][y][z]= ans/(x+y+z);
}

int main()
{
    FASTIO;
    int n,t,x=0,y=0,z=0;
    cin>>n;
    memset(dp, -1, sizeof dp);
    loop(i, 0, n){
        cin>>t;
        if(t==1) x++;
        else if(t==2) y++;
        else z++;
    }
    prDouble(solve(x, y, z, n));
    return 0;
}


