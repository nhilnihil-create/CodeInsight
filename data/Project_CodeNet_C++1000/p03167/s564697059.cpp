#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
using iii = pair<ii, int>;
#define vt vector
#define pb push_back
#define pf push_front
#define mp make_pair
#define fi first
#define se second
#define __lcm(a, b) a * b / __gcd(a, b)x
const int MOD = 1e9 + 7;
const int INF = 2e9;
const int N = 1e3 + 5;

int R, C;
int dp[N][N];
char grid[N][N];

int add(int x, int y) {
    return ((x % MOD) + (y % MOD)) % MOD;
}

bool inside(int r, int c) {
    return r >= 1 && r <= R && c >= 1 && c <= C;
}

int f(int r, int c) {
    if(grid[r][c] == '#') return 0;
    if(!inside(r, c)) return 0;
    if(r == R && c == C) return 1;
    int &sol = dp[r][c];
    if(sol != -1) return sol;
    return sol = add(f(r + 1, c), f(r, c + 1));
}

void solve() {
    cin >> R >> C;
    for(int i = 1; i <= R; i++) {
        for(int j = 1; j <= C; j++) {
            cin >> grid[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));
    cout << f(1, 1) % MOD << "\n";
}

int main() {
 
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    
}