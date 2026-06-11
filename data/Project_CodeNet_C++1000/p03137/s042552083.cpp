#include <bits/stdc++.h>
#define int long long
#define rng(i, l, r) for (size_t i = (l); i < (r); ++i)
#define rep(i, n) rng(i, 0, n)
#define gnr(i, l, r) for (size_t i = (r)-1; i >= (l); i--)
#define per(i, b) gnr(i, 0, b)
#define ALL(obj) (obj).begin(), (obj).end()    //1,2,3,...
#define rALL(obj) (obj).rbegin(), (obj).rend() //...,3,2,1
using namespace std;
const int INF = 1e18;
const int MOD = 1000000007;

void solve()
{

    // remove the bottom 3 lines when you submit this code.
    std::ifstream in("sample.txt");
    std::cin.rdbuf(in.rdbuf());

    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<int> x(m);
    rep(i, m) cin >> x[i];

    sort(ALL(x));
    int maxL = x[m - 1] - x[0];

    vector<int> len;
    rep(i, m - 1) len.push_back(x[i + 1] - x[i]);
    sort(rALL(len));

    if (n >= m)
    {
        cout << 0 << endl;
        return;
    }
    else
    {
        int sum = 0;
        rep(i, n - 1) sum += len[i];
        cout << maxL - sum << endl;
        return;
    }
}

signed main()
{
    solve();
    return 0;
}