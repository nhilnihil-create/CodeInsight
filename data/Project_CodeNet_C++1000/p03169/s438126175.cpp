#include<bits/stdc++.h>
using namespace std;
int ara[400],n;
int one=0,two=0,three=0;
 
double dp[302][302][302];
 
double f(int x,int y,int z){
   
    double res,j,k,l,m;
    j=x,k=y,l=z,m=n;
    if(x<0 || y<0 || z<0) return 0;
    else if(x==0 && y==0 && z==0) return 0;
     if(dp[x][y][z]>-10) return dp[x][y][z];
    else{
        res=(m+j*f(x-1,y,z)+k*f(x+1,y-1,z)+l*f(x,y+1,z-1))/m;
        res=res/(1-((m-(x+y+z))/m));
    }
   dp[x][y][z]=res;
    return res;
}
 
 
int main(){
   for(int i=0;i<302;i++)  for(int j=0;j<302;j++)  for(int k=0;k<302;k++) dp[i][j][k]=-50;
    cin >> n;
    for(int i=0;i<n;i++) cin >> ara[i];
    for(int i=0;i<n;i++){
        if(ara[i]==1) one++;
        else if(ara[i]==2) two++;
        else three++;
    }
   
   
  
    
    
    
    printf("%0.12lf\n",f(one,two,three));
    
}
