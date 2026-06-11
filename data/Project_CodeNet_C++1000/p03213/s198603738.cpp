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
    const int M = 100;
    vector<int> geq(M + 1);
    for (int i = 1; i <= n; i++) geq[cnt[i]]++;
    for (int i = M - 1; i >= 0; i--) geq[i] += geq[i + 1];
    int ans = 0;
    ans += geq[74];
    ans += geq[24] * (geq[2] - 1);
    ans += geq[14] * (geq[4] - 1);
    ans += geq[4] * (geq[4] - 1) / 2 * (geq[2] - 2);
    cout << ans << endl;
    return 0;
}
