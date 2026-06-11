#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    int res = 0;
    for (int h = 0; h <= 28; h++)
    {
        vector<int> v[2], cnt(2, 0);
        for (int i = 0; i < n; i++)
        {
            if (b[i] & (1 << h))
                v[1].push_back(b[i] & ((1 << h) - 1));
            else
                v[0].push_back(b[i] & ((1 << h) - 1));
        }
        sort(v[0].begin(), v[0].end());
        sort(v[1].begin(), v[1].end());
        for (int i = 0; i < n; i++)
        {
            int val = ((1 << h) - 1) ^ (a[i] & ((1 << h) - 1));
            if (a[i] & (1 << h))
            {
                int a = v[1].end() - upper_bound(v[1].begin(), v[1].end(), val), b = (int)v[1].size() - a;
                int c = v[0].end() - upper_bound(v[0].begin(), v[0].end(), val), d = (int)v[0].size() - c;
                cnt[1] += a, cnt[0] += b;
                cnt[1] += d, cnt[0] += c;
            }
            else
            {
                int a = v[1].end() - upper_bound(v[1].begin(), v[1].end(), val), b = (int)v[1].size() - a;
                int c = v[0].end() - upper_bound(v[0].begin(), v[0].end(), val), d = (int)v[0].size() - c;
                cnt[1] += b, cnt[0] += a;
                cnt[1] += c, cnt[0] += d;
            }
        }
        if (cnt[1] & 1)
            res |= (1 << h);
    }
    cout << res << endl;
    return 0;
}
