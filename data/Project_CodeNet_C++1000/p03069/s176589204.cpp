#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, x, n) for (int i = x; i < (n); i++)
#define all(n) begin(n), end(n)
struct cww
{
    cww()
    {
        ios::sync_with_stdio(false);
        cin.tie(0);
    }
} star;
const long long INF = numeric_limits<long long>::max();
typedef long long ll;
typedef vector<int> vint;
typedef vector<char> vchar;
typedef vector<vector<int>> vvint;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef unsigned long long ull;
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
int main()
{
    int N;
    cin >> N;
    string S;
    cin >> S;
    int B = count(all(S), '#'), W = 0, ans = INT_MAX;
    ans = N - W - B;
    rep(i, N)
    {
        if (S[i] == '.')
        {
            W++;
        }
        else
        {
            B--;
        }
        ans = min((i + 1 - W) + (N - (i + 1)) - B, ans);
    }
    cout << ans;
    return 0;
}