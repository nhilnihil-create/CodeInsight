#include <bits/stdc++.h>
typedef long long int LL;
typedef unsigned long long int ULL;
using namespace std;

// 插入此處

char t[200005], d[200005];

int main() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    for (int i = 0; i < q; i++) {
        cin >> t[i] >> d[i];
    }
    int ans = 0;
    int l = 0, r = n + 1;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        int cur = mid - 1;
        bool ok = false;
        for (int i = 0; i < q; i++) {
            if (s[cur] == t[i]) {
                if (d[i] == 'R') {
                    cur++;
                } else {
                    cur--;
                }
            }
            if (cur == -1) {
                ok = true;
                break;
            } else if (cur == n) {
                break;
            }
        }
        if (ok) {
            l = mid;
        } else {
            r = mid;
        }
    }
    ans += l;
    l = 0; r = n + 1;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        int cur = n - mid;
        bool ok = false;
        for (int i = 0; i < q; i++) {
            if (s[cur] == t[i]) {
                if (d[i] == 'R') {
                    cur++;
                } else {
                    cur--;
                }
            }
            if (cur == n) {
                ok = true;
                break;
            } else if (cur == -1) {
                break;
            }
        }
        if (ok) {
            l = mid;
        } else {
            r = mid;
        }
    }
    ans += l;
    printf("%d\n", max(n - ans, 0));
}
