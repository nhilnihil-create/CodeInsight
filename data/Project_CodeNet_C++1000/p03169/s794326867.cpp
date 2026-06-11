#include <iostream>
#include<cstring>
#include<iomanip>
using namespace std;

double dp[301][301][301];

double f(int x,int y,int z,int n){
    if(x<0 || y<0 || z<0)
    return 0;
    if(x==0 && y==0 && z==0)
    return 0;
    if(dp[x][y][z]>0)
    return dp[x][y][z];
    
    return dp[x][y][z] = (double)(n + x*f(x-1,y,z,n) + y*f(x+1,y-1,z,n) + z*f(x,y+1,z-1,n))/(x+y+z);
}

double expectedMoves(int a[],int n){
    memset(dp,-1,sizeof dp);
    int freq[4] = {0};
    for(int i=0;i<n;i++)
    freq[a[i]]++;
    return f(freq[1],freq[2],freq[3],n);
}

int main() {
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<setprecision(10)<<expectedMoves(a,n);

    return 0;
}