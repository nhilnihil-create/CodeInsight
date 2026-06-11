#include<bits/stdc++.h>
using namespace std;

double dp[301][301][301];

double f(int x,int y,int z,int &n){
    if(x < 0 || y < 0 || z < 0){return 0;}
    if(x == 0 && y == 0 && z == 0){
        return 0;
    }
    if(dp[x][y][z]>-0.9){
        return dp[x][y][z];
    }
    double ev=n+x*f(x-1,y,z,n)+y*f(x+1,y-1,z,n)+z*f(x,y+1,z-1,n);
    return dp[x][y][z]=ev/(x+y+z);
    
}

int main(){
    memset(dp,-1,sizeof(dp));
    int n,x;
    cin>>n;
    int ones=0,two=0,three=0;
    for(int i=1;i<=n;i++){
        cin>>x;
        if(x==1)ones++;
        else if(x==2)
            two++;
        else
            three++;
        
    }
    cout<<fixed<<setprecision(9)<<f(ones,two,three,n)<<"\n";
    return 0;
}