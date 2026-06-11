#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

vector<pair<long long, long long> > prime_factorize(long long N) {
    vector<pair<long long, long long> > res;
    for (long long a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;
        long long ex = 0;
        while (N % a == 0) {
            ++ex;
            N /= a;
        }
        res.push_back({a, ex});
    }
    if (N != 1) res.push_back({N, 1});
    return res;
}

int main() {
    long long N, p;
    cin >> N >> p;
    const auto &res = prime_factorize(p);

    ll ans = 1;
    for (auto x : res) {
        for (int j = 1; x.second >= N * j; ++j) {
            ans *= x.first;
        }
    }
    cout << ans << endl;
}