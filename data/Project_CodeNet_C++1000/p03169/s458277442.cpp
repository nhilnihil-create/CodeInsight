#include <bits/stdc++.h>
using namespace std;

double dp[301][301][301];

double solve(int x, int y, int z, int &n){

    if(x<0 || y<0 || z<0)
        return 0;

    if(x == 0 && y == 0 && z == 0)
        return 0;

    if(dp[x][y][z] > -0.9)
        return dp[x][y][z];

    double exp = n + x*solve(x-1,y,z,n) + y*solve(x+1,y-1,z,n) + z*solve(x,y+1,z-1,n);

    return dp[x][y][z] = exp/(x+y+z);

}

int main() {
    
    int n;
    cin>>n;

    memset(dp,-1,sizeof dp);

    int ones = 0, twos = 0, threes = 0;

    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        if(a==1)
            ones++;
        else if(a==2)
            twos++;
        else    
            threes++;
    }

    cout<<fixed<<setprecision(10)<<solve(ones,twos,threes,n);

    return 0;
}
