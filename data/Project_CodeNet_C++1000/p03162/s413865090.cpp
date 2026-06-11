#include<iostream>
#define N 3
#define loop(i,n) for(int i=0;i<n;i++)
using namespace std;
int a[100002][N];
int dp[100002][N+1];
int n;

int min_cost(int n,int c){
    if(n==0) return 0;
    if(dp[n][c]!=-1) return dp[n][c]; 
    int ans=0;
    for(int i=0;i<=2;i++)
        if(c==3) 
             ans=max(ans,a[n-1][i]+min_cost(n-1,i));
        else if(c!=i) 
             ans=max(ans,a[n-1][i]+min_cost(n-1,i));
    return dp[n][c]=ans;
}

int main()
{
    cin>>n;
    loop(i,n) loop(j,N) 
    cin>>a[i][j];
    loop(i,n+1) loop(j,N+1)
    dp[i][j]=-1;
    cout<<min_cost(n,3)<<endl;
    return 0;
}


