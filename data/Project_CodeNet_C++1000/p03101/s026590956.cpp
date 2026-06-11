#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
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
    int H, W;
    int h, w;
    cin >> H >> W >> h >> w;
    cout << (H - h) * (W - w) << endl;

    return 0;
}
