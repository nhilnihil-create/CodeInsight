#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000

vector<long long> enum_divisors(long long N) {
    vector<long long> res;
    for (long long i = 1; i * i <= N; ++i) {
        if (N % i == 0) {
            res.push_back(i);
            // 重複しないならば i の相方である N/i も push
            if (N / i != i)
                res.push_back(N / i);
        }
    }
    // 小さい順に並び替える
    sort(res.begin(), res.end());
    return res;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N;
    cin >> N;
    vector<ll> en = enum_divisors(N);
    ll sum = 0;
    rep(i, en.size()) {
        ll m = en[i] - 1;
        if (m == 0)
            continue;
        if (N / m == N % m)
            sum += m;
    }

    cout << sum << endl;
}