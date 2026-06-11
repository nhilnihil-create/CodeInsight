#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
using iii = pair<ii, int>;
#define vt vector
#define pq priority_queue
#define pb push_back
#define pf push_front
#define mp make_pair
#define fi first
#define se second
#define __lcm(a, b) a * b / __gcd(a, b)x
const int MOD = 1e9 + 7;
const int INF = 2e9;
const int N = 3e3 + 5;

int n, half;
double prob[N];
double dp[N][N];
bool vis[N][N];

double f(int idx, int tail) {
    if(idx > n) return tail < half ? 1 : 0;
    double &sol = dp[idx][tail];
    if(vis[idx][tail]) return sol;
    vis[idx][tail] = true;
    sol = f(idx + 1, tail) * prob[idx] + f(idx + 1, tail + 1) * (1 - prob[idx]);
    return sol;
}

void solve() {
    cin >> n;
    half = n / 2 + (n & 1 ? 1 : 0);
    for(int i = 1; i <= n; i++) {
        cin >> prob[i];
    }
    cout << fixed << setprecision(10) << f(1, 0) << "\n";
}

int main() {
 
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    
}