#include<bits/stdc++.h>
#define int long long
using namespace std;


const int N = 5005, INF = 1e18;



int n, A, B, a[N], dp[N];

main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> A >> B;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    int ans = INF;
    for(int i = 1; i <= n; i++){
        int cur = 0;
        dp[i] = INF;
        for(int j = i - 1; j >= 0; j--){
            if(a[i] > a[j]){
                dp[i] = min(dp[i], dp[j] + cur * A + (i - j - 1 - cur) * B);
            }
            else{
                cur += 1;
            }
        }
        ans = min(ans, dp[i] + (n - i) * B);
    }
    a[n + 1] = INF;
    for(int i = n; i >= 1; i--){
        int cur = 0;
        dp[i] = INF;
        for(int j = i + 1; j <= n + 1; j++){
            if(a[i] < a[j]){
                dp[i] = min(dp[i], dp[j] + cur * B + (j - i - 1 - cur) * A);
            }
            else{
                cur += 1;
            }
        }
        ans = min(ans, (i - 1) * A + dp[i]);
    }
    cout << ans;
}
