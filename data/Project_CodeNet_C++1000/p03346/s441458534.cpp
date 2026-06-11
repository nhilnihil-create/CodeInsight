#include <bits/stdc++.h>
using namespace std;

int n;
const int maxn = 2e5 + 5;
int a[maxn];

int dp[maxn];

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    memset(dp, -1, sizeof(dp));
    int ans = 0;
    for(int i = 1;i <= n;i++){
        if(dp[a[i] - 1] == -1){
            dp[a[i]] = 1;
        }else{
            dp[a[i]] = dp[a[i] - 1] + 1;
        }
        ans = max(ans, dp[a[i]]);
    }
    cout << n - ans << endl;
    return 0;
}
