#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

int main()
{
    int n, m, c;
    cin >> n >> m >> c;
    vector<int> b(m), a(m);
    rep(i, m) cin >> b[i];

    int res = 0;
    rep(i, n)
    {
        rep(j, m) cin >> a[j];
        int tmp = c;
        rep(j, m) tmp += b[j] * a[j];
        if (tmp > 0)
            res++;
    }

    cout << res << '\n';
    return 0;
}
