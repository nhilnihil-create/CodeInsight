#include <bits/stdc++.h>
using namespace std;


#define ll long long 

#define nax 301

double dp[nax][nax][nax];


double solve(int x, int y, int z, int n) {
    if(x < 0 || y < 0 || z < 0) return 0;
    
    if(x+y+z == 0) return 0;
    
    
    if(dp[x][y][z] > -0.9) return dp[x][y][z];
    
    
    int sum = x+y+z;
    
    double ans = n + (x*solve(x-1, y,z,n)) + (y*solve(x+1, y-1, z,n)) + (z*solve(x, y+1, z-1,n));
    return dp[x][y][z] = ans/sum;
    
}



int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin>>n;
    
    int x = 0, y= 0, z = 0;
    for(int i = 1; i<= n; i++) {
        int tmp; cin>>tmp;
        if(tmp == 1) x++;
        else if(tmp == 2) y++;
        else z++;
    }
    
    
    for(int i = 0; i < nax; i++){
        for(int j = 0; j < nax; j++){
            for(int k = 0; k < nax; k++) 
            dp[i][j][k] = -1;
        }
    }
    
    
    cout<<fixed<<setprecision(10)<<solve(x,y,z,n);
    
    
	return 0;
}
