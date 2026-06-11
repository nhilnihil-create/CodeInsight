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
    vector<ll> data(n);
    ll takahashi = 0, aoki = 0;
    for (int i = 0; i < n; i++)
    {
        ll a, b;
        cin >> a >> b;
        aoki += b;
        data[i] = a + b;
    }
    sort(data.begin(), data.end());
    reverse(data.begin(), data.end());
    for (int i = 0; i < n; i += 2)
    {
        takahashi += data[i];
    }
    cout << takahashi - aoki << endl;
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