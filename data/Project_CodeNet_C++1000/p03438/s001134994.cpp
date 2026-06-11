#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1001001001;
const ll LINF = 1LL << 60;
const int MOD = 1'000'000'007;

template <typename T>
void print(const T &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (i)
            cout << ' ';
        cout << v[i];
    }
    cout << endl;
}

template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}

template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}

// const int MAX = 1010;

int main()
{
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    ll a_sum = 0;
    ll b_sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        a_sum += a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        b_sum += b[i];
    }
    ll req = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] < b[i])
        {
            req += (b[i] - a[i] + 1) / 2;
        }
    }
    if (req <= b_sum - a_sum)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}