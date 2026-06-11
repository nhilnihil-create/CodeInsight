#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define ld long double
#define INF 1000000000000000000
typedef pair<ll, ll> pll;
typedef pair<int, int> pint;

vector<pll> enum_divisors(long long N) {
    vector<pll> res;
    for (long long i = 1; i * i <= N; ++i) {
        if (N % i == 0) {
            // 重複しないならば i の相方である N/i も push
            if (N / i != i)
                res.push_back({i, N / i});
        }
    }
    // 小さい順に並び替える
    sort(res.begin(), res.end());
    return res;
}

int main() {
    ll N;
    cin >> N;
    vector<pll> en = enum_divisors(N);
    ll ans = 0;
    rep(i, en.size()) {
        if (en[i].first < en[i].second - 1)
            ans += (en[i].second - 1);
    }

    cout << ans << endl;
    return 0;
}