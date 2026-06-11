// Author: Sayantanu
#include <bits/stdc++.h>

using namespace std;

#define ll long long int
const int mod = 1e9 + 7;

struct day{
    int a;
    int b;
    int c;
};

int main() {
    //code
    int n;
    cin>>n;
    vector<day> arr(n);
    for(int i=0;i<n;i++)cin>>arr[i].a>>arr[i].b>>arr[i].c;
    int dp[3] = {0,0,0};
    for(int i=0;i<n;i++){
        int a = max(dp[1] + arr[i].a ,dp[2] + arr[i].a);
        int b = max(dp[0] + arr[i].b ,dp[2] + arr[i].b);
        int c = max(dp[0] + arr[i].c ,dp[1] + arr[i].c);
        dp[0]=a,dp[1]=b,dp[2]=c;
    }
    cout<<max({dp[0],dp[1],dp[2]});
    return 0;
}


