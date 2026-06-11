#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
double dp[305][305][305];
double solve(int x,int y,int z){
    if(x<0 || y<0 || z<0){
        return 0;
    }
    if(x==0 && y==0 && z==0){
        return 0;
    }
    double &ans=dp[x][y][z];
    if(ans>0){
        return ans;
    }
    ans=(n+x*solve(x-1,y,z)+y*solve(x+1,y-1,z)+z*solve(x,y+1,z-1))/(x+y+z);
    return ans;
}
int32_t main() {
    memset(dp,-1,sizeof(dp));
    cin>>n;
    int x=0,y=0,z=0;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        if(a==1) x++;
        else if(a==2) y++;
        else z++;
    }
    cout<<fixed<<setprecision(10)<<solve(x,y,z)<<endl;
}
