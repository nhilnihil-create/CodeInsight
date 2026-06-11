#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for (int i = a; i < b; i++)
int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, 0, n)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    ll m = a[0];
    int idx = 0;
    while (true)
    {
        bool ok = true;
        ll tmpm = m;
        rep(i, 0, n)
        {
            if (a[i] == tmpm)
                continue;

            a[i] = a[i] % tmpm;
            if (a[i] != 0)
            {
                if (m > a[i])
                {
                    m = a[i];
                    ok = false;
                }
            }
        }
        if (ok)
        {
            break;
        }
        a.erase(remove(a.begin(), a.end(), 0), a.end());
    }

    cout << m << endl;
    return 0;
}
