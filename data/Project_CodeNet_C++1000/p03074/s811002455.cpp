
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5 + 5;
int n, m, k, res, sum, cnt, zcnt, kcnt, l;
string s;
int a[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    cin >> s;

    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
            ++cnt;
            if (zcnt != 0) {
                a[m++] = -zcnt;
                zcnt = 0;
            }
        } else {
            ++zcnt;
            if (cnt != 0) {
                a[m++] = cnt;
                cnt = 0;
            }
        }
    }
    if (cnt != 0) {
        a[m++] = cnt;
    }
    if (zcnt != 0) {
        a[m++] = -zcnt;
    }
    for (int i = 0; i < m; ++i) {
        sum += abs(a[i]);
        if (a[i] < 0) {
            ++kcnt;
        }
        while (kcnt > k) {
            int lv = a[l++];
            if (lv < 0) kcnt--;
            sum -= abs(lv);
        }
        res = max(res, sum);
    }
    cout << res << endl;

    return 0;
}

