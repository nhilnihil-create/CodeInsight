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

bitset<4000010> dp;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> a(n);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    dp.set(0);
    for (int i = 0; i < n; i++)
    {
        dp |= (dp << a[i]);
    }
    for (int i = 1; i <= 4000000; i++)
    {
        if (dp[i] && 2 * i >= sum)
        {
            cout << i << endl;
            return 0;
        }
    }
}
