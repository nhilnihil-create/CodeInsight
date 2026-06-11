#include <bits/stdc++.h>

int main() {
    using namespace std;
    constexpr unsigned long MOD = 1000000007;
    unsigned long N;
    cin >> N;
    vector<unsigned long> weight(N);
    {
        vector<unsigned long> hoge(N), fuga(N, 1), piyo(N, 1);
        iota(hoge.begin(), hoge.end(), 1UL);
        partial_sum(hoge.rbegin(), hoge.rend() - 1, fuga.rbegin() + 1, [&MOD](auto a, auto b){return a * b % MOD;});
        partial_sum(hoge.begin(), hoge.end() - 1, piyo.begin() + 1, [&MOD](auto a, auto b){return a * b % MOD;});
        for(unsigned long i = 0; i < N; ++i)weight[i] = fuga[i] * piyo[i] % MOD;
    }
    vector<unsigned long> A(N);
    for(auto& i : A)cin >> i;
    partial_sum(weight.begin(), weight.end(), weight.begin());
    unsigned long ans{0};
    for(unsigned long i = 0; i < N; ++i)ans += A[i] * ((weight[i] + weight[N - i - 1] - weight[0]) % MOD) % MOD;
    cout << ans % MOD << endl;
    return 0;
}