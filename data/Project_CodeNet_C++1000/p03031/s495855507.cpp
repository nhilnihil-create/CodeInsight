#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rng(i, a, b) for (int i = int(a); i < int(b); i++)
#define rep(i, b) rng(i, 0, b)
#define gnr(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
#define per(i, b) gnr(i, 0, b)
#define bg begin()
#define ed end()
#define all(x) x.bg, x.ed
#define vi vector<int>
template <class t, class u>
bool chmax(t &a, u b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}
template <class t, class u>
bool chmin(t &a, u b)
{
    if (b < a)
    {
        a = b;
        return true;
    }
    return false;
}

ll mod = 1000000007;
int n, m;
vi p;

bool isAllOn(int num, vector<vector<int>> &vvi)
{
    rep(i, m)
    {
            int sum = 0;
        rep(j, vvi[i].size())
        {
            if ((num & (1 << (vvi[i][j] - 1))) == 0)
            {
                sum++;
            }
        }
            if(sum%2!=p[i]){
                return false;
            }
    }
    return true;
}
signed main()
{
    cin >> n >> m;
    vector<vector<int>> vvi;
    rep(i, m)
    {
        int k;
        cin >> k;
        vi s(k);
        rep(j, k)
        {
            cin >> s[j];
        }
        vvi.push_back(s);
    }
    rep(i, m)
    {
        int a;
        cin >> a;
        p.push_back(a);
    }
    int ans = 0;
    rep(i, 1 << n)
    {
        if (isAllOn(i, vvi))
        {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}