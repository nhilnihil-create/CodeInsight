#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
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
const long long INF = 1LL << 60;

int main()
{
    int a, b;
    int ans = 0;
    cin >> a >> b;
    if (a >= (b + 1))
    {
        ans += 2 * a - 1;
    }
    else if (b >= (a + 1))
    {
        ans += 2 * b - 1;
    }
    else
    {
        ans += (a + b);
    }
    cout << ans << endl;

    return 0;
}
