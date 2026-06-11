#include <iostream>
#include <vector>
#define ll long long
using namespace std;

template <typename T>
struct BIT {
    const ll UNITY_SUM = 0; // 0
    vector<ll> data; // 値
    // 初期化
    BIT(ll n)
        : data(n + 1)
    {
    }
    void init(ll n) { data.assign(n + 1, UNITY_SUM); }
    // data[x]にaを加える
    inline void add(ll a, ll x)
    {
        for (ll i = a; i < (ll)data.size(); i += i & -i) {
            data[i] = data[i] + x;
        }
    }
    //  data[a]までのの和を求める
    inline ll sum(ll a)
    {
        ll res = UNITY_SUM;
        // 最初に立っているbitから求める
        for (ll i = a; i > 0; i -= i & -i) {
            res += data[i];
        }
        return res;
    }
    // 累積和の差から区間の和を求める
    inline ll sum(ll a, ll b)
    {
        return sum(b - 1) - sum(a - 1);
    }
};

main()
{
    // input
    ll N;
    cin >> N;
    vector<ll> a(N);
    for (ll i = 0; i < N; ++i)
        cin >> a[i];
    // 答えがhighになるように2分探索する
    ll low = 0, high = 1 << 30;
    const ll len = N + 1; // 要素数+1
    while (high - low > 1) {
        ll mid = (low + high) / 2;
        long long num = 0; //
        BIT<long long> bit(N * 2 + 10);
        ll sum = 0;
        bit.add(sum + len, 1); // sum+geta以降に1を足す
        for (ll i = 0; i < N; ++i) {
            ll val;
            if (a[i] <= mid) {
                val = 1; // 中央値より大きいなら1
            } else {
                val = -1; // 中央値より小さいなら-1
            }
            sum += val; // 中央値より大きい値が何個あるか
            num += bit.sum(1, sum + len); // numに区間の和を足す
            bit.add(sum + len, 1); // sum+geta以降に1を足す
        }
        // 半数が中央値より上なら上半分に答えがある
        if (2 * num > (N + 1) * N / 2) {
            high = mid;
        } else {
            low = mid;
        }
    }
    cout << high << endl;
}