#include <bits/stdc++.h>
#define INF 1e18
#define int long long
#define Rep(i, a, n) for (int i = (a); i < (n); i++)
#define Repr(i, n, a) for (int i = (n); i >= (a); i--)
#define rep(i, n) Rep(i, 0, n)
#define repr(i, n) Repr(i, n, 0)
#define all(a) a.begin(), a.end()
using namespace std;
typedef pair<int, int> P;
typedef pair<int, P> PP;
const int mod = 1000000007;

int n, q;
string s;
vector<pair<char, char>> v;

bool check(int pos)
{
    rep(i, q)
    {
        char c1 = v[i].first, c2 = v[i].second;
        if (c1 != s[pos])
            continue;
        if (c2 == 'R')
            pos++;
        else
            pos--;
        if (pos == -1 || pos == n)
            return true;
    }
    return false;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> q >> s;
    v.resize(q);
    rep(i, q) cin >> v[i].first >> v[i].second;
    int l = 0, r = n;
    while (r - l > 1)
    {
        int mid = (r + l) / 2;
        if (check(mid))
            l = mid;
        else
            r = mid;
    }
    int pos_l = l;
    l = 0, r = n;
    while (r - l > 1)
    {
        int mid = (r + l) / 2;
        if (check(mid))
            r = mid;
        else
            l = mid;
    }
    int pos_r = l;
    cout << max(0LL, pos_r - pos_l) << endl;
}