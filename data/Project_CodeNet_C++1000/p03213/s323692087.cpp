#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

map<long long, int> prime_factorize(long long n) {
    map<long long, int> res;
    for (long long p = 2; p * p <= n; ++p) {
        while (n % p == 0) { ++res[p]; n /= p; }
    }
    if (n != 1) res[n] = 1;
    return res;
}

int main() {
    int n; cin >> n;
    vector<int> cnt(n + 1);
    for (int i = 1; i <= n; i++) {
        for (auto &p: prime_factorize(i)) cnt[p.first] += p.second;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) if (cnt[i] >= 74) ans++;
    for (int i = 1; i <= n; i++) if (cnt[i] >= 2) {
        for (int j = 1; j <= n; j++) if (i != j && cnt[j] >= 24) ans++;
    }
    for (int i = 1; i <= n; i++) if (cnt[i] >= 4) {
        for (int j = 1; j <= n; j++) if (i != j && cnt[j] >= 14) ans++;
    }
    for (int i = 1; i <= n; i++) if (cnt[i] >= 2) {
        for (int j = 1; j <= n; j++) if (i != j && cnt[j] >= 4) {
            for (int k = j + 1; k <= n; k++) if (i != k && cnt[k] >= 4) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
