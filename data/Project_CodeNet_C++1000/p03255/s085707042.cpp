#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <complex>
#include <map>
#include <set>
#include <bitset>

#define forin(i, f, t) for(ll i = f; i < t; i++)

using namespace std;
using ll = long long;
using ull = unsigned long long;
using Pair = pair<ll, ll>;

ll N, X;
vector<ll> xs;

void input() {
    cin >> N >> X;
    xs.resize(N);
    for (auto& v : xs)
        cin >> v;
}

ull solve() {
    ll cxs[N];
    cxs[0] = xs[0];
    for (int i = 1; i < N; i++) {
        cxs[i] = cxs[i - 1] + xs[i];
        cerr << cxs[i] << endl;
    }
    
    ull ans = numeric_limits<ull>::max();
    for (auto k = 1; k <= N; k++) {
        ull cAns = X * k;
        for (auto i = 0; i < ceil(float(N) / k); i++) {
            ll b = N - k * i - 1;
            ll clen = (b - k) >= 0 ? cxs[b] - cxs[b - k] : cxs[b];
            if (i == 0) {
                cAns += clen * 5;
            } else {
                cAns += clen * (2 * (i + 1) + 1);
            }
         }
        ans = min(ans, cAns);
    }
    
    return ans + X * N;
}

int main() {
    input();
    
    cout << solve() << endl;
    
    return 0;
}

