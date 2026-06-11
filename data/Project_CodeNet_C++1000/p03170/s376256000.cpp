#include<bits/stdc++.h>
using namespace std;
bool dp[101][100001];
int main(){
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    sort(a,a+n);
    memset(dp,0,sizeof dp);
    for(int j=1;j<=k;j++){
        if(j<a[0])
        dp[0][j]=0;
        else dp[0][j]=!(dp[0][j-a[0]]);
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<=k;j++){
            if(j<a[i])
            dp[i][j]=dp[i-1][j];
            else{ int b=i;
                for(int b=i;b>=0;b--){
                    if(dp[i][j-a[b]]==0){
                    dp[i][j]=1;
                    }
                }
            }
        }
    }
    if(dp[n-1][k])
    cout<<"First";
    else cout<<"Second";
}