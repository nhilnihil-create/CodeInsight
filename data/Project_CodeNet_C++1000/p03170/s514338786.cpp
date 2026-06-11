#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++)scanf("%d",&arr[i]);
    vector<bool>dp(k+1,false);
    dp[0]=false;
    for(int i=1;i<k+1;i++){
        for(int j=0;j<n && arr[j]<=i;j++)
        dp[i] = dp[i] || !dp[i-arr[j]];
    }/*
    for(int i=0;i<k+1;i++){
        if(dp[i])printf("1 ");
        else printf("0 ");
    }
    cout<<"\n";*/
    if(dp[k])
    printf("First");
    else
    printf("Second");
    return 0;
}