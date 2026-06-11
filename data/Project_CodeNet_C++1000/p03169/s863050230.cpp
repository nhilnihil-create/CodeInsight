#include <bits/stdc++.h>
using namespace std;
#define doublepr(x) cout<<fixed<<setprecision(10)<<x
double dp[301][301][301];

double solve(int x, int y, int z, int n) {
    if(x < 0 || y < 0 || z < 0) return 0;
    if(x == 0 && y == 0 && z == 0) return 0;
    if(dp[x][y][z] > -0.9) return dp[x][y][z];
    double exp = n + x*solve(x-1, y, z, n) + y*solve(x+1, y-1, z, n) + z*solve(x, y+1, z-1, n);
    return dp[x][y][z] = exp/(x+y+z);
}

int main() {
    int N; cin>>N;
    int one, two, three;
    one = two = three = 0;
    for(int i=0; i<N; i++) {
        int tmp; cin>>tmp;
        if(tmp == 1) one++;
        else if(tmp == 2) two++;
        else three++;
    }
    memset(dp, -1, sizeof dp);
    solve(one, two, three, N);
    doublepr(dp[one][two][three]);
    return 0;
}
