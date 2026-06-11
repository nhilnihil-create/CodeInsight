#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

const int mod = 1e9 + 7;
int n, a[MAXN];
int spfract[MAXN];

int pwlog(int x, int pw) {
    if (!pw)
        return 1;
    int a = pwlog(x, pw >> 1);
    return 1LL * a * a % mod * ((pw & 1) ? x : 1) % mod;
}

int fmod(int x) {
    x %= mod;
    return (x < 0) ? (x + mod) : x;
}

int main() {
    ios::sync_with_stdio(0);

    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    spfract[1] = 1;
    for (int i = 2; i <= n; ++i)
        spfract[i] = (spfract[i - 1] + pwlog(i, mod - 2)) % mod; 

    long long sol = 0;
    for (int i = 1; i <= n; ++i)
        sol = (sol + 1LL * a[i] * fmod(spfract[i] + spfract[n - i + 1] - 1)) % mod;
    for (int i = 1; i <= n; ++i)
        sol = sol * i % mod;

    cout << sol << "\n";

    return 0;
}