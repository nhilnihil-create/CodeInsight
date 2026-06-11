#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<n;i++)
#define inf 1e9+7
using namespace std;
typedef long long ll;
const double pi=acos(-1);

int main(){
    int n,k;
    cin >> n >> k;
    vector<int> h(n);
    for(int i=0;i<n;i++) cin >> h[i];
    vector<int> dp(n,inf);
    dp[0]=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<=min(i+k,n-1);j++){
            dp[j]=min(dp[j],dp[i]+abs(h[i]-h[j]));
        }
    }
    cout << dp[n-1] << endl;
}