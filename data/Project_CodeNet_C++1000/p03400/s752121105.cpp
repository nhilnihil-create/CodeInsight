#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

int main()
{
    int n, d, x;
    cin >> n >> d >> x;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    rep(i, n)
    {
        int cnt = 0, day = 1;
        while (day <= d)
        {
            day += a[i];
            cnt++;
        }
        x += cnt;
    }
    cout << x << '\n';
    return 0;
}
