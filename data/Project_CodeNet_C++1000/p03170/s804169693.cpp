#include <bits/stdc++.h>
using namespace std;
int main()
{   
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(int& x:a){
        cin>>x;
    }
    int dp[k+1];
    dp[0] =0;
    for(int i=1;i<=k;i++){
        dp[i] = 0;
        for(int x:a){
            if(i>=x && dp[i-x]==0){
                dp[i] =1;
                break;
            }
        }
    }
    if(dp[k]==1) cout<<"First"<<endl;
    else cout<<"Second"<<endl;
}