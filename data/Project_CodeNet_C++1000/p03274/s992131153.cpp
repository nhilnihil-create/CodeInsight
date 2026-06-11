#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k, min(0), ans(-1);
    cin >> n >> k;
    vector<int> x(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> x[i];
    }
    for (int i = 0; i < n - k + 1; ++i)
    {
        int start = x[i], end = x[i + k - 1];
        if (start <= 0 && end >= 0)
        {
            int min = (-start > end) ? 2 * end - start : end - 2 * start;
            if (min < ans || ans < 0)
                ans = min;
        }
    }
    if (ans < 0)
    { //全部が正または全部が負
        for (int i = 0; i < n; ++i)
            x[i] = abs(x[i]);
        sort(x.begin(), x.end());
        ans = x[k - 1];
    }
    cout << ans << endl;
}