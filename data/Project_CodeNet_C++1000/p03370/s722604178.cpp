#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()
#define all2(a, b) (a).begin(), (a).begin() + (b)
#define debug(vari) cerr << #vari << " = " << (vari) << endl;

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> m(n);
    rep(i, n) cin >> m[i];

    int sum = 0, mi = 1001001001;
    rep(i, n)
    {
        sum += m[i];
        mi = min(mi, m[i]);
    }

    cout << (x - sum) / mi + n << endl;

    return 0;
}
