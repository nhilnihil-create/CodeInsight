#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int n, m, c;
    cin >> n >> m >> c;

    vector<int> b(m);
    rep (i, m)
        cin >> b[i];

    int ans = 0;
    rep (i, n)
    {
        int sum = 0;
        rep (j, m)
        {
            int a;
            cin >> a;
            sum += a * b[j];
        }
        if (sum + c > 0)
            ans++;
    }

    cout << ans << endl;
    return 0;
}