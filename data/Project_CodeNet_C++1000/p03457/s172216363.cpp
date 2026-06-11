#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int N;
    cin >> N;
    int ct = 0, cx = 0, cy = 0;
    rep(i, N)
    {
        int t, x, y;
        cin >> t >> x >> y;
        int d = abs(x + y - (cx + cy));
        int dt = t - ct;
        cx = x;
        cy = y;
        ct = t;
        if (!(dt >= d && (dt % 2 == d % 2)))
        {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}