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
struct UnionFind
{
    vector<int> data;

    UnionFind(int sz)
    {
        data.assign(sz, -1);
    }

    bool unite(int x, int y)
    {
        x = find(x), y = find(y);
        if (x == y)
            return (false);
        if (data[x] > data[y])
            swap(x, y);
        data[x] += data[y];
        data[y] = x;
        return (true);
    }

    int find(int k)
    {
        if (data[k] < 0)
            return (k);
        return (data[k] = find(data[k]));
    }

    int size(int k)
    {
        return (-data[find(k)]);
    }
    bool same(int x, int y)
    {
        return find(x) == find(y);
    }
};

int main()
{
    int N, M;
    cin >> N >> M;
    UnionFind uf(N), init(N);
    vll a(M), b(M);
    vll ans(M);
    for (size_t i = 0; i < M; i++)
    {
        cin >> a[i] >> b[i];
        a[i]--;
        b[i]--;
        init.unite(a[i], b[i]);
    }
    set<int> cnt;
    for (size_t i = 0; i < N; i++)
    {
        cnt.insert(init.find(i));
    }
    ll start = 0;
    for (auto &&i : cnt)
    {
        start += ((ll)init.size(i) * (ll)(init.size(i) - 1)/2);
    }
    reverse(all(a));
    reverse(all(b));
    for (size_t i = 0; i < M-1; i++)
    {
        if (!uf.same(a[i], b[i]))
        {
            ll apar = uf.find(a[i]),bpar = uf.find(b[i]);
            ll as = uf.size(a[i]),bs = uf.size(b[i]);
            ans[i + 1] = ans[i] + as*bs;
            uf.unite(a[i], b[i]);
        }else
        {
            ans[i+1]=ans[i];
        }
        
    }

    reverse(all(ans));
    for (size_t i = 0; i < M; i++)
    {
        cout <<start - ans[i] << endl;
    }

    return 0;
}