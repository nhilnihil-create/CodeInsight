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
    int n, m;
    string s, t;
    cin >> n >> m >> s >> t;
    ll gcd = __gcd(n, m);
    ll lcm = n / gcd * m;

    for (int i = 0; i < gcd; i++)
    {
        if (s[i * n / gcd] != t[i * m / gcd])
        {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << lcm << endl;
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