#include<bits/stdc++.h>
using namespace std;
int n;
double dp[305][305][305];
double solve(int x, int y, int z){
    if(x==0 && y==0 && z==0) return 0;
    if(x<0 || y<0 || z<0) return 0;
    if(dp[x][y][z]>0) return dp[x][y][z];
    int tot = x+y+z;
    return dp[x][y][z] = (n*1.0+x*solve(x-1,y,z)+y*solve(x+1,y-1,z)+z*solve(x,y+1,z-1))/tot;

}
int main(){
cin >> n;
int one=0,two=0,three=0;
for(int i=0; i<n; i++){
int x;
cin >> x ;
if(x==1) one++;
else if(x==2) two++;
else three++;
}
memset(dp, -1, sizeof dp);
cout << fixed << setprecision(10) << solve(one,two,three) << endl;


return 0;
}
