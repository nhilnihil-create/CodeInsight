#include <bits/stdc++.h>
using namespace std;
#define int long long
using P = pair<int, int>;
using V = vector<int>;
constexpr array<int, 4> dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};
constexpr int INF = 1234567890, MOD = 1000000000 + 7;
// constexpr int MOD = 998244353;
// constexpr int INF2 = 1000000000000000000LL+7;
template <class T>
bool chmax(T &a, const T &b)
{
    if (a < b)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T &a, const T &b)
{
    if (b < a)
    {
        a = b;
        return 1;
    }
    return 0;
}
constexpr int ceil(int a, int b) { return (a + b - 1) / b; }
constexpr int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
constexpr int fact(int n) { return n > 1 ? n * fact(n - 1) % MOD : 1; }
constexpr int modpow(int a, int n)
{
    int rtn = 1;
    while (n > 0)
    {
        if (n & 1)
            rtn = rtn * a % MOD;
        a = a * a % MOD;
        n >>= 1;
    }
    return rtn;
}
int modinv(int a)
{
    int b = MOD, u = 1, v = 0;
    while (b)
    {
        int t = a / b;
        a -= t * b;
        swap(a, b);
        u -= t * v;
        swap(u, v);
    }
    u %= MOD;
    if (u < 0)
        u += MOD;
    return u;
}

constexpr bool canMakePair(P red, P blue) { return ((red.first < blue.first && red.second < blue.second) ? true : false); }

signed main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << setprecision(10);

    int n;
    cin >> n;
    vector<P> reds(n), blues(n);
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        reds[i] = {a, b};
    }
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        blues[i] = {a, b};
    }
    sort(reds.begin(), reds.end());
    sort(blues.begin(), blues.end());

    int n_pairs = 0;

    // 青い点について調べる
    for (int i = 0; i < n; i++)
    {
        // 青い点とペアが作れる赤い点の中で，もっともy座標が大きい点とペアを作る
        // 残りの青い点はこの青い点よりx座標が同じか大きい だからy座標が大きい（厳しい）点を貪欲的に取る
        int index_greedy_red_point = -1;
        int y_greedy_red_point = -1;

        for (int j = 0; j < n; j++)
        {
            // 今の青い点よりx座標が小さい赤い点を探す
            if (!(reds[j].first < blues[i].first))
                break;
            // この赤い点は青い点とペアを作れる
            if (reds[j].second < blues[i].second)
            {
                // y座標が最も大きい赤い点の情報を更新
                if (reds[j].second > y_greedy_red_point)
                {
                    index_greedy_red_point = j;
                    y_greedy_red_point = reds[j].second;
                }
            }
        }

        // 赤い点が見つかったなら ペアを作る 赤い点を使えなくする
        if (index_greedy_red_point != -1)
        {
            reds[index_greedy_red_point] = {INF, INF};
            sort(reds.begin(), reds.end());

            n_pairs++;
        }
    }

    cout << n_pairs << endl;
}
