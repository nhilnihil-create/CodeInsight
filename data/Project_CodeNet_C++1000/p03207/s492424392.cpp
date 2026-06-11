#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;

    vector<int> p(n);
    rep (i, n)
        cin >> p[i];

    sort(p.begin(), p.end());
    cout << accumulate(p.begin(), p.end() - 1, p[n - 1] / 2) << endl;
    return 0;
}