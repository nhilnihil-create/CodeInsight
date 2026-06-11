#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, x, n) for (int i = x; i < (n); i++)
#define all(n) begin(n), end(n)
struct cww
{
    cww()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);
    }
} star;
const long long INF = numeric_limits<long long>::max();
typedef long long ll;
typedef vector<int> vint;
typedef vector<char> vchar;
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
    int N;
    cin >> N;
    vll A(N), B(N);

    ll dif = 0, ans = 0, sum = 0, Max = 0;
    rep(i, N)
    {
        cin >> A[i];
        Max += A[i];
    }

    rep(i, N)
    {
        cin >> B[i];
        sum += B[i];
    }

    if (sum > Max)
    {
        cout << -1 << endl;
        return 0;
    }
    vector<pair<ll, ll>> AB(N);
    for (int i = 0; i < N; i++)
    {
        AB[i] = {A[i], B[i]};
    }
    sort(all(AB), [](pair<ll, ll> a, pair<ll, ll> b) {
        return a.first - a.second < b.first - b.second;
    });
    for (int i = 0; i < N; i++)
    {
        ll a = AB[i].first, b = AB[i].second;
        if (b - a > 0)
        {
        }
        else if (b == a)
        {
            ans++;
        }
        else
        {

            sum += (a - b);
            if (sum <= Max)
            {
                ans++;
            }
        }
    }

    cout << N - ans;
    return 0;
}