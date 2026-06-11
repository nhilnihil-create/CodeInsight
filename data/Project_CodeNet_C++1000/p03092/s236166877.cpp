#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define vi vector<int>
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define int long long

const int N = 5005;

int n, a, b;
int p[N];
int coor[N];
int notMove[N];
int dp[N][N], mn[N][N];

main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> a >> b;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        coor[p[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n + 1; j++) {
            int foo = mn[i - 1][j];
            if (coor[i - 1] < j) foo = min(foo, notMove[i - 1]);
            if (coor[i] >= j) {
                dp[i][j] = foo + b; 
            } else {
                dp[i][j] = foo + a;
            }
        }
        int foo = mn[i - 1][coor[i]];
        if (coor[i - 1] < coor[i]) {
            foo = min(foo, notMove[i - 1]);
        }
        notMove[i] = foo;
        mn[i][1] = dp[i][1];
        for (int j = 2; j <= n + 1; j++) {
            mn[i][j] = min(mn[i][j - 1], dp[i][j]);
        }
    }
    cout << min(mn[n][n + 1], notMove[n]);
    return 0;
}