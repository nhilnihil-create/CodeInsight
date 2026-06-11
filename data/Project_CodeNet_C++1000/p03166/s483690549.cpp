#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
using iii = pair<ii, int>;
#define pq priority_queue
#define vt vector
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define __lcm(a, b) a * b / __gcd(a, b)
const int MOD = 1e9 + 7;
const int INF = 1e9;
const int N = 1e5 + 5;

int n, m, a, b, ans;
int dp[N];
vt<int> v[N];

int f(int x) {
    if(!v[x].size()) return 0;
    int &sol = dp[x];
    if(sol != -1) return sol;
    sol = -INF;
    for(int u : v[x]) {
        sol = max(sol, 1 + f(u));
    }
    return sol;
}

void solve() {
    cin >> n >> m;
    while(m--) {
        cin >> a >> b;
        v[a].pb(b);
    }
    memset(dp, -1, sizeof(dp));
    ans = -INF;
    for(int i = 1; i <= n; i++) {
        ans = max(ans, f(i));
    }
    cout << ans << "\n";
}

int main() {
 
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    
}