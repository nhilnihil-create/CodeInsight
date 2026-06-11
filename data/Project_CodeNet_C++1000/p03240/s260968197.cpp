#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < n; i++)
#define INF 2147483647

int main()
{
    ll n;
    cin >> n;
    vector<ll> x(n);
    vector<ll> y(n);
    vector<ll> h(n);
    rep(i, n)
    {
        cin >> x[i] >> y[i] >> h[i];
    }

    rep(i, 100 + 1)
    {
        int flag = 1;
        rep(j, 100 + 1)
        {
            ll H = 0;
            ll u = 0 - 1; //過去の値を格納する場所
            flag = 1;
            ll min1 = INF;
            rep(k, n)
            {
                if (h[k] == 0)
                {
                    min1 = min(min1, h[k] + labs(x[k] - i) + labs(y[k] - j));
                    continue;
                }
                H = h[k] + labs(x[k] - i) + labs(y[k] - j);
                if (u == -1 && H <= min1)
                {
                    u = H;
                    continue;
                }
                if (u != H || H > min1 || u > min1)
                {

                    flag = 0;
                    break;
                }
            }
            if (H > min1)
            {
                flag = 0;
            }
            if (flag == 1)
            {
                cout << i << " " << j << " " << H;
                break;
            }
        }
        if (flag == 1)
        {
            break;
        }
    }
}
