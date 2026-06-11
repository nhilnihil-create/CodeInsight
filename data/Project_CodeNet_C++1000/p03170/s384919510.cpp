#include <bits/stdc++.h>
#define int long long
using namespace std;


int32_t main() {
    int n,k;
    cin>>n>>k;
    int a[n+1];
    bool dp[100005]={false};
    for(int i=0;i<n;i++){
        cin>>a[i];
        dp[a[i]]=true;
    }
    for(int i=1;i<=k;i++){
        for(int j=0;j<n;j++){
            if(i>=a[j]){
                if(!dp[i-a[j]]) dp[i]=true;
            }
        }
    }
    if(dp[k]) cout<<"First"<<endl;
    else cout<<"Second"<<endl;
}
