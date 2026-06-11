#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0, i##_len = (int)(n); i < i##_len; i++)
using namespace std;
using Int = long long;

vector<pair<Int, Int>> primeFactors(Int n) {
    vector<pair<Int, Int>> result;
    Int factor = 0;
    Int factorCount = 0;
    Int q = n;
    if (n >= 2) {
        for (Int i = 2; i * i <= n;) {
            if (q % i == 0) {
                if (i != factor) {
                    factor = i;
                    factorCount = 1;
                } else {
                    factorCount++;
                }
                q /= i;
            } else {
                if (factor > 0) {
                    result.push_back(make_pair(factor, factorCount));
                    factor = 0;
                }
                i++;
            }
        }
    }
    if (q > 1) {
        result.push_back(make_pair(q, 1));
    }

    return result;
}

int main() {
    Int n, p;
    cin >> n >> p;
    auto factors = primeFactors(p);
    Int ans = 1;
    for (auto &factor : factors) {
        rep(i, factor.second / n) ans *= factor.first;
    }
    cout << ans << endl;
}
