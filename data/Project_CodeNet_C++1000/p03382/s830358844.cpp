#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < n; i++)

int main()
{
    ll n;
    cin >> n;
    vector<ll> a(n);

    ll max1;
    rep(i, n)
    {
        cin >> a[i];
        if (i == 0)
        {
            max1 = a[i];
        }
        else
        {
            max1 = max(max1, a[i]);
        }
    }
    //10** 5となっているのでどうするかの問題はある。どう考えても絶対値が近いものが勝ち
    ll t; //絶対値の近さを格納
    ll u;
    rep(i, n)
    {
        if (a[i] == max1)
        {
            continue;
        }
        if (i == 0)
        {
            t = labs(a[i] - max1 / 2);
            u = a[i];
        }
        else
        {
            if (t > (ll)labs(a[i] - max1 / 2))
            {
                t = (ll)labs(a[i] - max1 / 2);
                u = a[i];
            }
        }
    }
    cout << max1 << " " << u;
}