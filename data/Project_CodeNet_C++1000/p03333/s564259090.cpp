#include "bits/stdc++.h"

using namespace std;

using ll = long long;
using ld = long double;
using P = pair<int, int>;
constexpr ld EPS = 1e-12;
constexpr int INF = numeric_limits<int>::max() / 2;
constexpr int MOD = 1e9 + 7;

template <typename T>
void printv(const vector<T> &v)
{
    int sz = v.size();
    for (int i = 0; i < sz; i++)
    {
        cout << v[i] << " \n"[i == sz - 1];
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<ll> l(n), r(n);
    for (int i = 0; i < n; i++)
        cin >> l[i] >> r[i];
    sort(l.rbegin(), l.rend());
    sort(r.begin(), r.end());

    ll ret = 0, sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += l[i];
        ret = max(ret, sum);
        sum -= r[i];
        ret = max(ret, sum);
    }
    sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum -= r[i];
        ret = max(ret, sum);
        sum += l[i];
        ret = max(ret, sum);
    }
    cout << ret * 2 << endl;
}
