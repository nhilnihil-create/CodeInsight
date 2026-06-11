#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using pint = pair<int, int>;

int main()
{
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;

    vector<int> sum(n + 1, 0);
    for (int i = 1; i < n; ++i)
    {
        sum[i + 1] = sum[i];
        if (s[i] == 'C')
            if (s[i - 1] == 'A')
                sum[i + 1] = sum[i] + 1;
    }
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        int ans = sum[r] - sum[l];
        cout << ans << endl;
    }
}