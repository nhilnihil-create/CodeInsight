#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000
typedef pair<ll, ll> pll;

int N, A, B, C;
vector<int> L;

int rec(int i, int a, int b, int c) {
    if (i == N) {
        if (!a || !b || !c)
            return 1e9;
        return abs(a - A) + abs(b - B) + abs(c - C);
    }

    int res = rec(i + 1, a, b, c);

    res = min(res, rec(i + 1, a + L[i], b, c) + (a ? 10 : 0));
    res = min(res, rec(i + 1, a, b + L[i], c) + (b ? 10 : 0));
    res = min(res, rec(i + 1, a, b, c + L[i]) + (c ? 10 : 0));

    return res;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N >> A >> B >> C;
    L.resize(N);
    rep(i, N) { cin >> L[i]; }

    cout << rec(0, 0, 0, 0) << endl;
}