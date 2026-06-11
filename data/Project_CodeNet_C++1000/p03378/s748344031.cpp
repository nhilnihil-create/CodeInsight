#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

int main()
{
    int n, m, x;
    cin >> n >> m >> x;
    vector<int> a(m);
    rep(i, m) cin >> a[i];
    a.push_back(x);
    sort(all(a));

    int res;
    rep(i, m + 1) if (a[i] == x) res = i;

    cout << min(res, m - res) << '\n';
    return 0;
}
