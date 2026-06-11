#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define MIN(a, b) ((a) > (b) ? (b) : (a))
#define MAX(a, b) ((a) < (b) ? (b) : (a))

const long long INF = 1LL << 60;
typedef long long ll;
const long long MOD = 1000000000 + 7;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> x(m);
    rep(i, m) cin >> x[i];
    sort(x.begin(), x.end());

    vector<ll> diffs;
    for (int i = 1; i < x.size(); ++i)
        diffs.push_back(x[i] - x[i - 1]);
    sort(diffs.begin(), diffs.end(), greater<ll>());

    ll res = x.back() - x[0];
    for (int i = 0; i < min((int)diffs.size(), n - 1); ++i)
        res -= diffs[i];
    cout << res << endl;
    return 0;
}