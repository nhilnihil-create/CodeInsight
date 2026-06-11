#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()
#define all2(a, b) (a).begin(), (a).begin() + (b)
#define debug(vari) cerr << #vari << " = " << (vari) << endl;
const int MOD = 1e9 + 7;

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> m(n);
    rep(i, n) cin >> m[i];

    int s = 0;
    rep(i, n) s += m[i];
    sort(all(m));

    cout << n + (x - s) /m[0]  << endl;
    return (0);
}
