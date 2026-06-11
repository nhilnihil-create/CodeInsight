#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
#include <vector>
#define ll long long int
#define mp make_pair
#define pb push_back
#define vi vector<int>
using namespace std;
vector<ll> groupvalue;
vector<ll> dp;
int n;
ll solve(int left){
    if(dp[left]!=-1){
        return dp[left];
    }
    dp[left]=groupvalue[left];
    for(int s=left;s;s=(s-1)&left){
        if(s==left){
            continue;
        }
        dp[left]=max(dp[left],solve(left^s) + solve(s));
    }
    return dp[left];
}
ll solve(){
    cin>>n;
    int value[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>value[i][j];
        }
    }
    groupvalue.resize((1<<n),0);
    dp.resize((1<<n),-1);
    for(int i=0;i<(1<<n);i++){
        for(int j=0;j<n;j++){
            if(i&(1<<j)){
                for(int k=j+1;k<n;k++){
                     if(i&(1<<k)){
                         groupvalue[i]+=value[j][k];
                     }
                }            
            }
        }
    }
    return solve((1<<n) -1);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<solve();
}