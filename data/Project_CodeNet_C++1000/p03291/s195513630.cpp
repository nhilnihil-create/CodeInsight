#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define dbg(x) cerr << #x << " = " << x << endl
#define _ << ' ' <<
using namespace std;
using ll = long long;
using vi = vector<int>;

const int mod = 1000000007;
int add(int a, int b) { return (a += b) < mod? a : a - mod; }
int sub(int a, int b) { return (a -= b) >=  0? a : a + mod; }
int mul(int a, int b) { return 1LL * a * b % mod; }
void adds(int& a, int b) { a = add(a, b); }
void subs(int& a, int b) { a = sub(a, b); }
void muls(int& a, int b) { a = mul(a, b); }
void maxs(int& a, int b) { a = max(a, b); }
void mins(int& a, int b) { a = min(a, b); }
int pwr(int a, ll p) {
    if (p == 0) return 1;
    if (p & 1) return mul(a, pwr(a, p - 1));
    return pwr(mul(a, a), p / 2);
}
int inv(int a) { return pwr(a, mod - 2); }

string s;
int n, dp[100000][4];

int f(int k, int u)
{
    if (k == n)
        return u == 3;
    if (dp[k][u] != -1)
        return dp[k][u];

    int sol = 0;
    if (s[k] == '?')
    {
        // A
        if (u == 0)
            adds(sol, f(k + 1, 1));
        adds(sol, f(k + 1, u));

        // B
        if (u == 1)
            adds(sol, f(k + 1, 2));
        adds(sol, f(k + 1, u));

        // C
        if (u == 2)
            adds(sol, f(k + 1, 3));
        adds(sol, f(k + 1, u));
    }
    if (s[k] == 'A')
    {
        if (u == 0)
            adds(sol, f(k + 1, 1));
        adds(sol, f(k + 1, u));
    }
    if (s[k] == 'B')
    {
        if (u == 1)
            adds(sol, f(k + 1, 2));
        adds(sol, f(k + 1, u));
    }
    if (s[k] == 'C')
    {
        if (u == 2)
            adds(sol, f(k + 1, 3));
        adds(sol, f(k + 1, u));
    }

    return dp[k][u] = sol;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> s;
    n = s.size();
    memset(dp, -1, sizeof dp);
    cout << f(0, 0);
}
