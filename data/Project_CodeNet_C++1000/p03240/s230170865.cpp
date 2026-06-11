#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

int main()
{
    int n;
    cin >> n;
    vector<int> x(n), y(n), h(n);
    rep(i, n) cin >> x[i] >> y[i] >> h[i];

    int tmp;
    rep(i, n)
    {
        if (h[i])
        {
            tmp = i;
            break;
        }
    }

    rep(cx, 100 + 1)
    {
        rep(cy, 100 + 1)
        {
            int H = h[tmp] + abs(x[tmp] - cx) + abs(y[tmp] - cy);
            bool ck = true;
            rep(i, n)
            {
                int hh = max(H - abs(x[i] - cx) - abs(y[i] - cy), 0);
                if (hh != h[i])
                    ck = false;
            }
            if (ck)
            {
                printf("%d %d %d\n", cx, cy, H);
            }
        }
    }
    // cout << ((a % 3 == 0 || b % 3 == 0 || (a + b) % 3 == 0) ? "Possible" : "Impossible") << "\n ";

    return 0;
}
