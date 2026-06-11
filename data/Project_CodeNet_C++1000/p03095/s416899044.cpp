#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
#define INF 1000000000000000000

int main() {
    int N;
    string S;
    cin >> N >> S;

    ll MOD = pow(10, 9) + 7;

    map<char, ll> cnt;
    rep(i, N) { cnt[S[i]]++; }

    ll res = 1;
    for (auto p : cnt)
        res *= (p.second + 1), res %= MOD;
    cout << res - 1 << endl;
}