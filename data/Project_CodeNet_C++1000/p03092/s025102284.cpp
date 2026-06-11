#include "bits/stdc++.h"
using namespace std;
typedef long long li;

const li mod = 1e9 + 7;

int main() {
    li n, a, b;
    cin >> n >> a >> b;
    vector<li> ps(n);
    for (int i = 0; i < n; ++i) {
        cin >> ps[i];
        ps[i]--;
    }

    vector<li> costs(n, 1LL << 60);
    for (int i = 0; i < n; ++i) {
        const li x = ps[i];
        costs[x] = a * i;
        for (int j = 0; j < i; ++j) {
            if (ps[j] < x) {
                costs[x] = min(costs[x], costs[ps[j]]);
                costs[ps[j]] += a;
            } else {
                costs[ps[j]] += b;
            }
        }
    }
    const li ans = *min_element(costs.begin(), costs.end());
    cout << ans << endl;
    
    return 0;
}
