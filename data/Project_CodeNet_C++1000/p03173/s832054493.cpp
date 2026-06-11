#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n;
ll arr[401];
ll dp[401][401];
ll prefix[401];

int main() {
    cin >> n;
    for (int i=1;i<=n;i++) {
        cin >> arr[i];
        prefix[i]=prefix[i-1]+arr[i];
    }

    for (int L=n;L>=1;L--) {
        for (int R=L+1;R<=n;R++) {
            dp[L][R]=LLONG_MAX;
            for (int M=L;M<R;M++) {
                dp[L][R]=min(dp[L][R],dp[L][M]+dp[M+1][R]+prefix[R]-prefix[L-1]);
            }
        }
    }
    cout << dp[1][n] << endl;
}

