#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(int &x:a){
        cin>>x;
    }
    vector<bool> dp(k+1);
    for(int i=1;i<=k;i++){
        for(int j=0;j<n;j++){
            if(i>=a[j] && !dp[i-a[j]])
                dp[i]=true;
        }
    }
    if(dp[k]) cout<<"First";
    else cout<<"Second";
}
