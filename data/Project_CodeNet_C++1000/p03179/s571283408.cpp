#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
#include <vector>
#define ll long long int
#define mp make_pair
#define pb push_back
#define vi vector<int>
using namespace std;
const ll p=1e9 + 7;
ll solve(){
   int n;
   cin>>n;
   string s;
   cin>>s;
   ll dp[n][n];
   ll dpsum[n+1]={0};
   dpsum[0]=0;
   for(int i=0;i<n;i++){
       dp[0][i]=1;
       dpsum[i+1]=i+1;
   }
   for(int i=1;i<n;i++){
       if(s[i-1]=='<'){
            for(int j=0;j<n-i;j++){
                dp[i][j]=dpsum[n-i+1]-dpsum[j+1];
                dp[i][j]%=p;
            }
        }
        if(s[i-1]=='>'){
            for(int j=0;j<n-i;j++){
                dp[i][j]=dpsum[j+1];
                dp[i][j]%=p;
            }
        }
        dpsum[0]=0;
        for(int j=1;j<=n-i;j++){
            dpsum[j]=dpsum[j-1]+dp[i][j-1];
        }
   }
   return dp[n-1][0];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<solve();
}