#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) { cin >> A[i]; }

    vector<ll> s(N + 1, 0);
    map<ll, ll> ma;
    rep(i, N) { s[i + 1] = s[i] + A[i]; }
    rep(i, N + 1) { ma[s[i]]++; }

    ll res = 0;
    for (auto p : ma) {
        ll num = p.second;
        res += num * (num - 1) / 2;
    }

    cout << res << endl;
}