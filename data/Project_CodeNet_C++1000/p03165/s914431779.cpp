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
const int N = 3e3 + 5;

int dp[N][N];
string s, t;
vt<char> v;

int f(int a, int b) {
    if(a == s.size() || b == t.size()) return 0;
    int &sol = dp[a][b];
    if(sol != -1) return sol;
    if(s[a] == t[b]) return sol = 1 + f(a + 1, b + 1);
    return sol = max(f(a + 1, b), f(a, b + 1));
}

void backtrack(int a, int b) {
    if(a == s.size() || b == t.size()) return;
    int temp = -INF, aplus, bplus;
    aplus = f(a + 1, b);
    bplus = f(a, b + 1);
    if(s[a] == t[b])
        temp = f(a + 1, b + 1);
    if(temp != -INF) {
        v.pb(s[a]);
        backtrack(a + 1, b + 1);
    } else if(aplus > bplus) 
        backtrack(a + 1, b);
    else 
        backtrack(a, b + 1);
}

void solve() {
    cin >> s >> t;
    memset(dp, -1, sizeof(dp));
    backtrack(0, 0);
    for(char x : v) 
        cout << x;
    cout << "\n";
}

int main() {
 
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    
}