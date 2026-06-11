


#include <bits/stdc++.h>
using namespace std;
double dp[301][301][301];
 
double solve(int x,int y, int z, int &n){

    if(x<0 || y<0 || z<0){
        return 0;

    }

    if(dp[x][y][z]>-0.9){
        return dp[x][y][z];
    }

    if(x==0 && y==0 && z==0){
        return 0;

    }

    double exp=n+x*solve(x-1,y,z,n)+y*solve(x+1,y-1,z,n)+z*solve(x,y+1,z-1,n);

    return dp[x][y][z]=(exp)/(x+y+z);





}

int main() {
    int n;
    cin>>n;
    int one=0,two=0,three=0;
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        if(x==1){
            one++;
        }else if(x==2){
            two++;
        }else if(x==3){
            three++;

        }
    }

    cout<<fixed<<setprecision(10)<<solve(one,two,three,n);






}
