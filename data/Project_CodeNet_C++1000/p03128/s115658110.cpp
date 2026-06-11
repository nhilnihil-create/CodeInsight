#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define rep(i, begin, n) for (int i = begin; i < n; i++)
#define repe(i, begin, n) for (int i = begin; i <= n; i++)
#define repr(i, begin, n) for (int i = begin; i > begin - n; i--)
#define repre(i, begin, end) for (int i = begin; i >= end; i--)

/*
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
*/

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

const string MINUSINF = "-";
void chmax(string &a, string b)
{
    if (a == MINUSINF)
    {
        a = b;
        return;
    }
    if (b.length() > a.length())
    {
        a = b;
        return;
    }
    if (b > a)
    {
        a = b;
    }
}

int N, M;
string dp[10101];
int match[10] = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int main()
{
    cin >> N >> M;
    vector<int> A(M);
    rep(i, 0, M)
    {
        cin >> A[i];
    }
    rep(i, 1, N)
    {
        dp[i] = MINUSINF;
    }
    dp[0] = "";
    rep(i, 0, N)
    {
        if (dp[i] == MINUSINF)
            continue;
        for (auto e : A)
        {
            char ec = e + '0';
            chmax(dp[i + match[e]], dp[i] + ec);
        }
    }
    cout << dp[N] << endl;
}
