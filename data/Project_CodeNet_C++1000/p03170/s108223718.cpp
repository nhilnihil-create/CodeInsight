#include <bits/stdc++.h> 
using namespace std; 
typedef long long ll;
const int mxN=1e9;
const ll mod = 1e9+7;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,k;
    cin>>n>>k;

    vector<int> v(n);

    for(int i=0;i<n;i++) cin>>v[i];

    bool dp[k+1][2];

    for(int i=0;i<=k;i++){
        dp[i][0]=0;
        dp[i][1]=1;
    }
    
    for(int i=0;i<=k;i++){
        for(int j=0;j<n;j++){
            if(i<v[j]) continue;
            if(dp[i-v[j]][1]){
                dp[i][0]=1;
                dp[i][1]=0;
            }
        }
    }

    if(dp[k][0]) cout<<"First";
    else cout<<"Second";
}