#include <bits/stdc++.h>
using namespace std;
double dp[301][301][301];
int n; 
double solve(int x, int y, int z){

if(x==0 && y==0 && z==0){
    return 0;
}
if(x<0 || y<0 || z<0){
    return 0;
}
if(dp[x][y][z]>-0.9){
    return dp[x][y][z];
}

   double e=n+x*solve(x-1,y,z)+ y*solve(x+1, y-1,z)+z*solve(x,y+1,z-1);
return dp[x][y][z]=e/(x+y+z);

}
int main() {
    memset(dp,-1,sizeof dp);
    cin>>n; int x;
    int one=0, two=0, three=0;
    for(int i=n;i>0;--i){
           cin>>x;
           if(x==1){
           one++;
           }
           else if(x==2){
               two++;
           } else{
               three++;
           }
    }
    //cout<<one<<" "<<two<<" "<<three<<"\n";
    cout<<fixed<<setprecision(20)<<solve(one, two, three);

    return 0;
}
