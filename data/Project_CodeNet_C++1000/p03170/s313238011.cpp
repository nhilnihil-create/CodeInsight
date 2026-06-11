#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
    int n,k;
    cin>>n>>k;
    vector<int>A(n);
    for (int i = 0;i<n;i++)cin>>A[i];
    vector<int>dp(k+1,0);
    for (int i = 1;i<=k;i++){
        for (auto val:A){
            if (val<=i && dp[i-val]==0){dp[i] = 1;break;}
        }
    }
    if (dp[k])cout<<"First";
    else cout<<"Second";
    return 0;
}