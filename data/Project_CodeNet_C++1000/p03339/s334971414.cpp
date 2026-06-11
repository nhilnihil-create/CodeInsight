/*
    飲んだ魔剤で家が建つ。
    created at: 2020-04-05 15:28:11
*/

#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(),(x).end()
#define rev(x) greater<(x)>()
#define MOD 1000000007
#define INF 1000000000

typedef long long LL;
typedef long double LD;

bool compare_by_b(pair<int, int> a, pair<int, int> b)
{
    if (a.second != b.second) {
        return a.second < b.second;
    } else {
        return a.first < b.first;
    }
}

LL modpower(LL n, LL m, LL mod) {
    if (m == 0) {
        return 1;
    } else if (m % 2 == 0) {
        LL p = modpower(n, m/2, mod);
        return p*p % mod;
    } else {
        return n*modpower(n, m-1, mod) % mod;
    }
}

LL modinv(LL n, LL mod) {
    return modpower(n, mod-2, mod);
}

LL modcombination(LL n, LL r, LL mod) {
    LL ret = 1;

    for (int i = 0; i < r; i++) {
        ret *= (n-i);
        ret %= mod;
        ret *= modinv(i+1, mod);
        ret % mod;
    }

    return ret % mod;
}

int gcd(int k, int l) {
    if (l > 0) return gcd(l, k%l);
    else return k;
}

ostringstream oss_global;
string s_global = oss_global.str();

int main()
{
    int n;
    string s;
    cin >> n >> s;

    int e[n], w[n];
    int prev = 0;
    for (int i = 0; i < n; i++) {
        e[i] = prev;
        if (s[i] == 'E') prev++;
    }
    prev = 0;
    for (int i = n-1; i > -1; i--) {
        w[i] = prev;
        if (s[i] == 'W') prev++;
    }

    int m = 0;
    for (int i = 0; i < n; i++) {
        int sum = e[i] + w[i];
        if (m < sum) m = sum;
    }

    int ans = n - m - 1;
    cout << ans << endl;

    return 0;
}
