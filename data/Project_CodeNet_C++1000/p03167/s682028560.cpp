#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
int h,w;
char ara[1001][1001];
long dp[1001][1001];
long func(int x,int y){
    if(dp[x][y]!=-1) return dp[x][y];
    long res;
    
    if(x==h-1 && y==w-1) res=1;
    else if(ara[x][y]!='.') res=0;
    else{
        int t1,t2;
        t1=func(x+1,y)%mod;
        t2=func(x,y+1)%mod;
        res=t1+t2;
    }
    dp[x][y]=res%mod;
    return dp[x][y];
}
int main(){
    memset(dp,-1,sizeof(dp));
    cin >> h >> w;
    
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin >> ara[i][j];
        }
    }
    
    cout << func(0,0) << endl;
    
}