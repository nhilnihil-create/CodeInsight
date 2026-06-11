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
    map<ll, int> mp;
    for (int i = 0; i < n; i++)
    {
        int d;
        cin >> d;
        mp[d]++;
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int t;
        cin >> t;
        if (!mp.count(t))
        {
            cout << "NO" << endl;
            return 0;
        }
        if (mp[t] <= 0)
        {
            cout << "NO" << endl;
            return 0;
        }
        mp[t]--;
    }
    cout << "YES" << endl;
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