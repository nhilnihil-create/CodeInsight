#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;

int main() {
    int n;
    cin >> n;
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c.at(i);
    }
    c.push_back(0);
    vector<long long> cnt(200001);
    vector<long long> dp(n + 1);
    cnt.at(c.at(0)) = 1;
    for (int i = 1; i <= n; i++) {
        if (c.at(i - 1) == c.at(i)) continue;

        dp.at(i) = cnt.at(c.at(i - 1));
        cnt.at(c.at(i)) += dp.at(i) % MOD;
        cnt.at(c.at(i)) %= MOD;
    }
    
    cout << dp.at(n) << endl;
}