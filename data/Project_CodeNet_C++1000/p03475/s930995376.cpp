#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int n;
    cin >> n;

    vector<int> c(n - 1), s(n - 1), f(n - 1);
    rep(i, n - 1)
    {
        cin >> c[i] >> s[i] >> f[i];
    }

    rep(i, n - 1)
    {
        int t = 0;
        for (int j = i; j < n - 1; j++)
        {
            if (t <= s[j])
                t = s[j];
            else
                t = ((t - s[j] + f[j] - 1) / f[j]) * f[j] + s[j];
            t += c[j];
        }
        cout << t << endl;
    }
    cout << 0 << endl;
}