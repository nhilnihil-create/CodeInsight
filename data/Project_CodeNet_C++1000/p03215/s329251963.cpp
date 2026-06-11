#include <bits/stdc++.h>
typedef long long int LL;
typedef unsigned long long int ULL;
using namespace std;

// 插入此處
int bit_count(LL n) {
    int ret = 0;
    while (n) {
        n >>= 1;
        ++ret;
    }
    return ret;
}

LL a[1002];
LL pre[1002];

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    int N, K; cin >> N >> K;
    for (int i = 0; i < N; ++i)  cin >> a[i];
    pre[0] = a[0];
    for (int i = 1; i < N; ++i)  pre[i] = pre[i-1] + a[i];
    vector<LL> v;
    int cur_bit = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = i+1; j < N; ++j) {
            LL sum = pre[j] - (i-1 >= 0 ? pre[i-1] : 0);
            v.push_back(sum);
            cur_bit = max(cur_bit, bit_count(sum));
        }
    }
    // for (auto x : v)  cout << x << ' ';
    // cout << endl;
    while (cur_bit > 0 && v.size() > K) {
        vector<LL> vv;
        for (int i = 0; i < v.size(); ++i) {
            if (v[i] & (1LL << (cur_bit-1)))  vv.push_back(v[i]);
        }
        if (vv.size() >= K)  v = move(vv);
        --cur_bit;
        // for (auto x : v)  cout << x << ' ';
        // cout << endl;
    }
    LL ans = v[0];
    for (int i = 1; i < K; ++i)  ans &= v[i];
    cout << ans << endl;
    return 0;
}
