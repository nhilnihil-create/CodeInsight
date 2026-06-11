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

int main()
{
    int n;
    cin >> n;
    int sum = 0;
    int current_x = 0;
    int current_y = 0;
    rep(i, n)
    {
        int t, x, y;
        cin >> t >> x >> y;
        int tt = t - sum;
        int xx = x - current_x;
        int yy = y - current_y;
        if (abs(xx) + abs(yy) <= tt && (abs(xx) + abs(yy)) % 2 == tt % 2)
        {
        }
        else
        {
            cout << "No" << endl;
            return 0;
        }
        sum = t;
        current_x=x;
        current_y = y;
    }
    cout << "Yes" << endl;

    return 0;
}