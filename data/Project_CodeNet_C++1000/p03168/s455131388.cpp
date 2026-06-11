#include <bits/stdc++.h>

using namespace std;

const int N = 3005;
int n;
double dp[N][N], arr[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    dp[1][0] = arr[1];
    dp[0][1] = 1 - arr[1];
    for(int i = 2; i <= n; i++){

        for(int j = i; j >= 0; j--){
            double a = 0;
            if(j - 1 >= 0){
                a += dp[j - 1][i - j] * arr[i];
            }
            if(i - j - 1 >= 0){
                a += dp[j][i - j - 1] * (1 - arr[i]);
            }
            dp[j][i - j] = a;
        }
    }
    double ans = 0;
    for(int i = n; i >= n / 2 + 1; i--){
        ans += dp[i][n - i];
    }
    cout << fixed << setprecision(10) << ans << '\n';
    return 0;
}