#include <bits/stdc++.h>
using namespace std;

const int N = 2e+5 + 5;
long long int a[N], n, s[N];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }
    long long int ans = 1e+18;
    for (int i = 2; i < n; i++)
    {
        long long int sl = s[i] - s[0], sr = s[n] - s[i];
        int ir = upper_bound(s + 1, s + n + 1, s[i] + sr / 2) - s;
        int il = upper_bound(s + 1, s + n + 1, sl / 2) - s;
        int ill = il, irr = ir;
        for (int k = -1; k <= 1; k++)
            for (int g = -1; g <= 1; g++)
            {
                il = ill + k, ir = irr + g;
                long long int p = max(max(s[il], s[i] - s[il]), max(s[ir] - s[i], s[n] - s[ir]));
                long long int q = min(min(s[il], s[i] - s[il]), min(s[ir] - s[i], s[n] - s[ir]));
                ans = min(ans, abs(p - q));
            }
    }
    cout << ans;
}