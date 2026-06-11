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
    ll n, m;
    cin >> n >> m;
    vector<ll> divs;
    for (int i = 1; i * i <= m; i++)
    {
        if (m % i == 0)
        {
            divs.push_back(i);
            divs.push_back(m / i);
        }
    }
    sort(divs.begin(), divs.end());

    // 二分探索
    ll left = 0;
    ll right = divs.size();

    while (right - left > 1)
    {
        ll mid = (left + right) / 2;
        if (m / divs[mid] < n)
        {
            right = mid;
        }
        else if (m / divs[mid] > n)
        {
            left = mid;
        }
        else
        {
            cout << divs[mid] << endl;
            return 0;
        }
    }
    cout << divs[int(left)] << endl;
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
}