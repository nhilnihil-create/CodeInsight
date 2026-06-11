#include<bits/stdc++.h>
using namespace std;

#define int       long long
#define nn        301
#define FAST      ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int n;
int x=0, y=0, z=0;
double dp[nn][nn][nn];

double solve(int x,int y,int z){
    if(x<0 || y<0 || z<0)
        return 0;

    if(x == 0 && y == 0 && z == 0)
        return 0;
    
    if(dp[x][y][z] > -0.9)
        return dp[x][y][z];

    double exp = n + x*solve(x-1,y,z) + y*solve(x+1,y-1,z) + z*solve(x,y+1,z-1);
    return dp[x][y][z] = exp/(x+y+z);
    
}

int32_t main(){
    FAST;
    cin>>n;
    memset(dp,-1,sizeof(dp));
    for(int i=1;i<=n;i++){
        int val; cin>>val;
        if(val == 1) x++;
        else if(val == 2) y++;
        else z++;
    }
    cout<<fixed<<setprecision(10);
    cout<<solve(x,y,z);
}
