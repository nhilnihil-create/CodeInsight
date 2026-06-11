#include <bits/stdc++.h>
using namespace std;

#define pr_double(x) cout << fixed << setprecision(10)<< x;


double dp[301][301][301];
double solve(int x,int y,int z,int& n){

    if(x<0 || y<0 || z<0){
      return 0;
    }

    if(x==0 && y==0 && z==0){
       return 0;
    }
 
    if(dp[x][y][z]>-0.9){
        return dp[x][y][z];
    }
   
    double exp = n + x*solve(x-1,y,z,n)+ y*solve(x+1,y-1,z,n)+ z*solve(x,y+1,z-1,n); 
    return dp[x][y][z]=(double)exp/(x+y+z);
}


int main(){

   int n,x;
   cin>>n;
   memset(dp,-1,sizeof dp);
   int one=0,two=0,three=0;

   for(int i=1;i<=n;i++){
       cin>>x;
       if(x==1){
        one++;
       }
       else if(x==2){
        two++;
       }
       else{
        three++;
       }
   }
   pr_double(solve(one,two,three,n));
}