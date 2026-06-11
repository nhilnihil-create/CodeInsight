#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5001;
const int INF = 1e18 + 7;
int n, A, B;
int a[N];
int p[N][N];
int sum(int x1, int y1, int x2, int y2) {
    if (x2 < x1 || y2 < y1) return 0;
    return p[x2][y2] - p[x2][y1 - 1] - p[x1 - 1][y2] + p[x1 - 1][y1 - 1];
}   
int dp[N];
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    cin >> n >> A >> B;
    int R = A; 
    int L = B;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        p[i][a[i]] = 1;
    }   
    bool sorted = 1;
    for (int i = 1; i <= n - 1; ++i) {
        sorted &= a[i] < a[i + 1];
    }   
    if (sorted) {
        cout << "0\n";
        exit(0);
    }   
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            p[i][j] += p[i - 1][j] + p[i][j - 1] - p[i - 1][j - 1];
        }   
    }   
    for (int i = 1; i <= n; ++i) {
        dp[i] = 0;
        for (int j = 1; j < i; ++j) {
            if (a[j] < a[i]) {
                dp[i] += min(L, R);
            }   
            else {
                dp[i] += R;
            }   
        }
        for (int j = 1; j < i; ++j) {
            if (a[j] < a[i]) {
                dp[i] = min(dp[i], dp[j] + sum(j + 1, a[j], i - 1, a[i]) * min(L, R) + sum(j + 1, 1, i - 1, a[j]) * L + sum(j + 1, a[i], i - 1, n) * R);
            }   
        }   
    }  
    int ans = INF;
    for (int i = 1; i <= n; ++i) {
        int nn = dp[i];
        for (int j = i + 1; j <= n; ++j) {
            if (a[j] < a[i]) {
                nn += L;
            }   
            else {
                nn += min(L, R);
            }   
        }   
        ans = min(ans, nn);
    }   
    cout << ans << '\n';
}   