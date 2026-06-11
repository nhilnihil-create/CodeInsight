#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define INF 1e9
int main(){
    int n,k;
    cin>>n>>k;
    vector<int>cost(n,0);
    for(int i=0;i<n;i++){
        cin>>cost[i];
    }
    vector <int> dp(n,INF);
    dp[0]=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<=i+k;j++){
            if(j<n){
                dp[j]=min(dp[j],dp[i]+abs(cost[i]-cost[j]));
            }
        }
    }
    cout<<dp[n-1];
    return 0;
}
