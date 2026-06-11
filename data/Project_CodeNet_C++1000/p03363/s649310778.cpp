#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    // 累積和と連想配列
    vector<ll> s(n+1);
    map<ll, ll> nums;
    rep(i, n) s[i+1] = s[i] + a[i];
    rep(i, n+1) nums[s[i]]++;

    // 集計処理
    ll ans = 0;
    for (auto it : nums) {
        ll num = it.second; // it.first が it.second 個ある
        ans += num * (num - 1) / 2; //組み合わせ計算 nC2 通り選ぶ。 1C2 = 0 となる。 
    }

    cout << ans << endl;


    return 0;
}