#include <bits/stdc++.h>
using namespace std;
using pint = pair<int, int>;
using ll = long long;
using pll = pair<ll, ll>;
#define FOR(i, begin, end) for (int i = (begin), i##_end_ = (end); i < i##_end_; i++)
#define IFOR(i, begin, end) for (int i = (end)-1, i##_begin_ = (begin); i >= i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
#define FI first
#define SE second
#define endl "\n"
#define ciosup cin.tie(0);ios::sync_with_stdio(false);
constexpr ll INF = 1e9 + 7;
constexpr ll MOD = 1e9 + 7;

int main()
{
    int n;
    cin >> n;
    cout << 180 * (n - 2) << endl;
}