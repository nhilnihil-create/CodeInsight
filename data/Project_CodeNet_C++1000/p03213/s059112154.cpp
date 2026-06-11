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

vector<long long> enum_divisors(long long n) {
    vector<long long> res;
    for (long long i = 1LL; i * i <= n; i++) {
        if (n % i != 0) continue;
        res.emplace_back(i);
        if (i != n / i) res.emplace_back(n / i);
    }
    sort(res.begin(), res.end());
    return res;
}

int main() {
    int n; cin >> n;
    vector<int> cnt(n + 1);
    for (int i = 1; i <= n; i++) {
        for (auto &p: prime_factorize(i)) cnt[p.first] += p.second;
    }
    cnt.erase(remove(cnt.begin(), cnt.end(), 0), cnt.end());
    int sz = cnt.size();
    auto ds = enum_divisors(75);
    vector<vector<int>> dp(sz + 1, vector<int>(75 + 1));
    dp[0][1] = 1;
    for (int i = 0; i < sz; i++) {
        for (auto d1: ds) for (auto d2: ds) if (d1 * d2 <= 75) {
            if (cnt[i] + 1 >= d2) dp[i + 1][d1 * d2] += dp[i][d1];
        }
    }
    cout << dp[sz][75] << endl;
    return 0;
}
