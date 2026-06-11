// https://abc097.contest.atcoder.jp/tasks/arc097_b
#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

vector<int> par; // 1..n

int root(int x) {
    if (x == par[x])
        return x;
    return par[x] = root(par[x]);
}

bool samegroup(int x, int y) { return root(x) == root(y); }

void unite(int x, int y) {
    x = root(x);
    y = root(y);
    if (x != y)
        par[x] = y;
}

int main(int argc, char** argv) {
    int n, m;
    cin >> n >> m;

    vector<int> p(n);
    par.resize(n);

    rep(i, n) { par[i] = i; }
    rep(i, n) {
        int t;
        cin >> t;
        p[t - 1] = i;
    }

    rep(i, m) {
        int x, y;
        cin >> x >> y;
        unite(x - 1, y - 1);
    }

    int ans = 0;
    rep(i, n) {
        if (root(p[i]) == root(i))
            ans++;
    }
    cout << ans << endl;
    return 0;
}
