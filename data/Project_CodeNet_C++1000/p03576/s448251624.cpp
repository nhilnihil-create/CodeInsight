#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> p(n, pair<int, int>());
    vector<int> x(n);
    vector<int> y(n);
    for (int i = 0; i < n; i++)
    {
        cin >> p.at(i).first >> p.at(i).second;
        x.at(i) = p.at(i).first;
        y.at(i) = p.at(i).second;
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    int64_t res = INT64_MAX;
    for (int il = 0; il < n; il++)
    {
        int64_t xl = x.at(il);
        for (int ir = il + 1; ir < n; ir++)
        {
            int64_t xr = x.at(ir);
            for (int ib = 0; ib < n; ib++)
            {
                int64_t yb = y.at(ib);
                for (int it = ib + 1; it < n; it++)
                {
                    int64_t yt = y.at(it);

                    int cnt = 0;
                    for (int i = 0; i < n; i++)
                    {
                        int64_t xi = p.at(i).first, yi = p.at(i).second;
                        if (xi < xl || xr < xi)
                            continue;
                        if (yi < yb || yt < yi)
                            continue;
                        cnt++;
                    }

                    if (cnt >= k)
                    {
                        int64_t w = xr - xl, h = yt - yb;
                        int64_t s = w * h;
                        if (s < res)
                            res = s;
                    }
                }
            }
        }
    }

    cout << res << endl;
}