#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main()
{
    int n, t, a;
    cin >> n >> t >> a;
    double te = 1e9;
    int id = -1;
    rep(i, n)
    {
        int h;
        cin >> h;
        double dh;
        dh = t - h * 0.006;
        dh = abs(a - dh);
        if (te > dh)
        {
            te = dh;
            id = i + 1;
        }
    }
    cout << id << endl;
    return 0;
}