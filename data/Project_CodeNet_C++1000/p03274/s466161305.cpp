#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;

    vector<int> xl, xr;
    int xi;
    for (int i = 0; i < N; i++)
    {
        cin >> xi;
        if (xi < 0)
        {
            xl.push_back(abs(xi));
        }
        else if (xi > 0)
        {
            xr.push_back(xi);
        }
        else
        {
            K--;
        }
    }
    reverse(xl.begin(), xl.end());

    if (K == 0)
    {
        cout << 0 << endl;
        return 0;
    }

    int res = INT_MAX;
    for (unsigned int nl = 0; nl <= (unsigned int)K; nl++)
    {
        unsigned int nr = K - nl;
        if (nl > xl.size() || nr > xr.size())
        {
            continue;
        }
        int l = (nl == 0) ? 0 : xl.at(nl - 1);
        int r = (nr == 0) ? 0 : xr.at(nr - 1);
        res = min(res, min(2 * l + r, l + 2 * r));
    }
    cout << res << endl;
}