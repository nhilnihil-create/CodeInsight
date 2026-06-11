#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+7;
int dp[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;

    int ans = 0;
    for (int i=1; i<=n; i++) {
        int x;
        cin>>x;
        dp[x] = dp[x-1]+1;
        ans = max(ans, dp[x]);
    }
    cout<<n-ans<<endl;
}
