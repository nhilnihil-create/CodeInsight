#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1001001001;
const ll LINF = 1001001001001001;
const int MOD = 1000000007;

template <typename T>
void print(const T &v);

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    vector<ll> am;
    ll am_total = 0;
    ll bm_total = 0, bm_cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == b[i])
        {
            continue;
        }
        else if (a[i] > b[i])
        {
            am_total += (a[i] - b[i]);
            am.push_back(a[i] - b[i]);
        }
        else if (b[i] > a[i])
        {
            bm_total += (b[i] - a[i]);
            ++bm_cnt;
        }
    }
    if (am_total < bm_total)
    {
        cout << -1 << endl;
        return 0;
    }
    if (bm_total == 0)
    {
        cout << 0 << endl;
        return 0;
    }
    sort(am.begin(), am.end());
    reverse(am.begin(), am.end());
    ll total = 0;
    for (int i = 0; i < am.size(); i++)
    {
        total += am[i];
        if (total >= bm_total)
        {
            cout << i + 1 + bm_cnt << endl;
            return 0;
        }
    }
    return 0;
}

// Use For Debug
template <typename T>
void print(T const &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (i)
            cout << ' ';
        cout << v[i];
    }
    cout << endl;
};