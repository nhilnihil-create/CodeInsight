#include<bits/stdc++.h>

using namespace std;

int const maxn = 2e5 + 5;
int a[maxn];
int inf = 1e9;
unordered_map < int, int > val;

inline int oks(int sz, int n) {
    set < int > R = {1};
    val[1] = 1;
    for (int i = 1; i <= n; ++i) {
        if (a[i] > a[i - 1]) continue;
        while (1) {
            int pos = (*R.rbegin());
            if (pos <= a[i]) break;
            R.erase(pos);
        }
        int good = a[i];
        while (1) {
            if ((int)R.size() == 0) return 0;
            int pos = (*R.rbegin()), c = val[pos];
            if (c == sz) {
                good = pos - 1;
                R.erase(pos);
                continue;
            }
            val[good] = c + 1;
            val[good + 1] = 1;
            R.insert(good);
            R.insert(good + 1);
            break;
        }
    }
    return 1;
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    int lef = 0, righ = n + 1;
    while (righ - lef > 1) {
        int mid = (righ + lef) / 2;
        if (oks(mid, n)) righ = mid;
        else lef = mid;
    }
    cout << righ << '\n';
    return 0;
}
