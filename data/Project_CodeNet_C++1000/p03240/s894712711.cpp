#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    vector<int> x(n), y(n), h(n);
    rep(i, n)
    {
        cin >> x[i] >> y[i] >> h[i];
    }
    rep(CX, 101) rep(CY, 101)
    {
        int H = -1;
        bool ok = true;
        //h[i] > 0
        rep(i, n)
        {
            if (h[i] > 0)
            {
                int tmpH = h[i] + abs(x[i] - CX) + abs(y[i] - CY);
                if (H == -1)
                    H = tmpH;
                if (H != tmpH)
                {
                    ok = false;
                    break;
                }
            }
        }
        if (!ok)
            continue;
        //h[i] = 0
        rep(i, n)
        {
            if (h[i] == 0)
            {
                int tmpH = h[i] + abs(x[i] - CX) + abs(y[i] - CY);
                if (H > tmpH)
                {
                    ok = false;
                    break;
                }
            }
        }
        if (!ok)
            continue;
        printf("%d %d %d\n", CX, CY, H);
        return 0;
    }
    return 0;
}