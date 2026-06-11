#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <bits/stdc++.h>
#include <iomanip>
#include <numeric>
#include <map>
#include <algorithm>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for (ll i = a; i < (ll)b; ++i)

#define rep(i, a, b) for (ll i = a; i < (ll)b; ++i)
#define INF 10e12
#define MAX 51000
#define all(x) (x).begin(), (x).end()
#define MX(x) *max_element(all(x))
#define MN(x) *min_element(all(x))

int main(void)
{
    int n, q;
    string s;
    cin >> n >> q >> s;
    vector<int> l(q), r(q);
    rep(i, 0, q) cin >> l[i] >> r[i];
    vector<int> cusum(n + 1);
    cusum[0] = 0;
    rep(i, 0, n)
    {
        if (s[max(i - 1, ll(0))] == 'A' && s[i] == 'C')
            cusum[i + 1] = cusum[i] + 1;
        else
            cusum[i + 1] = cusum[i];
    }
    rep(i, 0, q) cout << cusum[r[i]] - cusum[l[i]] << endl;
}
