#include <bits/stdc++.h>
typedef long long ll;
#define rep(i, a, b) for (int i = a; i < b; i++)
using namespace std;
int gcd(int a, int b)
{
    if (a % b == 0)
    {
        return (b);
    }
    else
    {
        return (gcd(b, a % b));
    }
}
int main()
{
    // 全ての位置との距離の最大公約数を求める
    int n;
    ll X;
    cin >> n >> X;
    ll a;

    n += 1;
    deque<ll> x(n);
    deque<ll> del(n - 1);
    x[0] = X;

    rep(i, 1, n)
    {
        cin >> x[i];
    }
    sort(x.begin(), x.end());

    rep(i, 0, n - 1)
    {
        del[i] = (abs(x[i + 1] - x[i]));
    }

    if (n - 1 == 1)
    {
        a = del[0];
    }
    else
    {
        a = gcd(del[0], del[1]);
        rep(i, 1, del.size())
        {
            a = gcd(a, del[i]);
            // cout << a << endl;
        }
    }
    cout << a << endl;
    return 0;
}
