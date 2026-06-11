#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

int main()
{
    int n;
    cin >> n;
    vector<int> p(n);
    rep(i, n) cin >> p[i];

    sort(all(p));
    int su = 0;
    rep(i, n) su += p[i];

    cout << su - p[n - 1] / 2 << '\n';
    return 0;
}
