#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define rep(i, begin, n) for (int i = begin; i < n; i++)
#define repe(i, begin, n) for (int i = begin; i <= n; i++)
#define repr(i, begin, n) for (int i = begin; i > begin - n; i--)
#define repre(i, begin, end) for (int i = begin; i >= end; i--)

template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return 1;
    }
    return 0;
}

template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return 1;
    }
    return 0;
}

const int inf = 1000000007;
const int MOD = 1000000007;
const long long INF = 1000000000000000007;

// -------------------------------------------------------

ll N, K;

int main()
{
    cin >> N >> K;
    if (K % 2 == 1)
    {
        ll v = N / K;
        cout << v * v * v << endl;
    }
    else
    {
        ll v = N / K;
        ll v2 = N / (K / 2);
        ll v3 = v2 - v;
        cout << v * v * v + v3 * v3 * v3 << endl;
    }
}
