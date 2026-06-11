#include<bits/stdc++.h>
using namespace std;

double dp[301][301][301];
double sushi(int x, int y, int z , int &n){
    if(x < 0 || y <0 || z<0)
       return 0;
    if(x == 0 && y == 0 && z == 0)
          return 0;

    if(dp[x][y][z] > -0.9){
        return dp[x][y][z];
    }

    double num = n + (x * sushi(x-1,y,z,n)) + (y * sushi(x+1,y-1,z,n)) + (z * sushi(x,y+1,z-1,n));
    return dp[x][y][z] = num/(x+y+z);
}


void solve(){
    int n;
    cin >> n;
    int x=0,y=0,z= 0;
    for(int i=0; i<n; i++){
        int no;
        cin >> no;
        if(no == 1)
           x++;
        if(no == 2)
           y++; 
        if(no == 3)
           z++;    
    }
    
    memset(dp, -1, sizeof(dp));
    cout <<fixed << setprecision(10)<<sushi(x,y,z,n);
    return;
}
int main(){
//  #ifndef ONLINE_JUDGE
//   freopen("input.txt", "r", stdin);
//   freopen("output.txt", "w", stdout);
// #endif 

 solve();

return 0;
}