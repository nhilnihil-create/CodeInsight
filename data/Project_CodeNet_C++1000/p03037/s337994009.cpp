#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> l(m), r(m);
    rep(i, m) cin >> l[i] >> r[i];
    sort(l.begin(), l.end());
    sort(r.begin(), r.end());
    int L = l[m - 1], R = r[0];
    int ans = R - L + 1;
    cout << max(ans, 0) << endl;
    return 0;
}