#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define sz(x) ((int)(x).size())
#define fill(v, h) memset((v), h, sizeof(v))
using namespace std;
const int MOD = 1000000007;

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

int main(void)
{
    int x;
    cin >> x;
    double ans = 1;
    for (int b = 2; pow(b, 2) <= x; b++)
    {
        for (int p = 2; pow(b, p) <= x; p++)
        {
            ans = max(ans, pow(b, p));
            cerr << ans << " ";
        }
    }
    cout << ans << endl;
    return 0;
}