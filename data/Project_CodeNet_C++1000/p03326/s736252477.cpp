#include <bits/stdc++.h>
using namespace std;
#define all(n) begin(n), end(n)
const long long INF = numeric_limits<long long>::max();
typedef long long ll;
typedef vector<int> vint;
typedef vector<vector<int>> vvint;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef unsigned long long ull;
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
template <typename T>
vector<T> make_v(size_t a) { return vector<T>(a); }

template <typename T, typename... Ts>
auto make_v(size_t a, Ts... ts)
{
    return vector<decltype(make_v<T>(ts...))>(a, make_v<T>(ts...));
}
template <typename T, typename V>
typename enable_if<is_class<T>::value == 0>::type
fill_v(T &t, const V &v) { t = v; }

template <typename T, typename V>
typename enable_if<is_class<T>::value != 0>::type
fill_v(T &t, const V &v)
{
    for (auto &e : t)
        fill_v(e, v);
}
int main()
{
    int N, M;
    cin >> N >> M;
    auto x = make_v<ll>(3,N);
    for (size_t i = 0; i < N; i++)
    {
        cin >> x[0][i] >> x[1][i] >> x[2][i];
    }
    ll ans = 0;
    int sign[3];
    for (int bit = 0; bit < (1 << 3); bit++)
    {
        vll vals;
        for (size_t i = 0; i < 3; i++)
        {
            if (bit & (1 << i))
            {
                sign[i] = 1;
            }
            else
            {
                sign[i] = -1;
            }
        }
        for (size_t i = 0; i < N; i++)
        {
            ll val = 0;
            for (size_t j = 0; j < 3; j++)
            {
                val += sign[j]*x[j][i];
            }
            vals.push_back(val);
        }
        ll sum = 0;
        sort(all(vals),greater<ll>());
        for (size_t i = 0; i < M; i++)
        {
            sum += vals[i];
        }
        chmax(ans,sum);

    }
    cout<<ans;
    return 0;
}