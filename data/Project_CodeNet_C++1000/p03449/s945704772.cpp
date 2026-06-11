#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    rep (i, n)
        cin >> a[i];
    rep (i, n)
        cin >> b[i];

    int ans = 0;
    bool flag;
    rep (i, n)
    {
        bool flag = true;
        int temp = 0;
        rep (j, n)
        {
            if (j == i)
            {
                flag = false;
                temp += a[j];
            }

            if (flag)
                temp += a[j];
            else
                temp += b[j];
        }
        ans = max(ans, temp);
    }

    cout << ans << endl;
    return 0;
}