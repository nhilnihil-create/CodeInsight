#include <bits/stdc++.h>
using namespace std;

signed main () {
	int n;
    cin >> n;
    vector < int > p(n + 1, 0);
    for (int i = 1; i <= n; ++i)
        cin >> p[i];
    vector < int > len (n + 1, -1000000);
    int k = 0;
    for (int i = 1; i <= n; ++i) {
        len[p[i]] = 1;
        len[p[i]] = max(len[p[i]], len[p[i] - 1] + 1);
        k = max(len[p[i]], k);
    }
    cout << n - k << '\n';
}
