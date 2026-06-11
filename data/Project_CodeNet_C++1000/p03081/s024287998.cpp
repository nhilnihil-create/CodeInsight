#include <bits/stdc++.h>

using namespace std;

const int max_n = 200222, inf = 1000111222;
const int max_c = 26;

int n, q, ans;
char s[max_n], c[max_n], dir[max_n];
vector<int> all[max_c];

int go(int x) {
    for (int i = 0; i < q; ++i) {
        if (s[x] == c[i]) {
            if (dir[i] == 'L') {
                --x;
            } else {
                ++x;
            }
        }
        if (x < 0 || x == n) {
            return x;
        }
    }
    return x;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%d%s", &n, &q, &s);
    for (int i = 0; i < n; ++i) {
        all[s[i] - 'A'].push_back(i);
    }
    for (int i = 0; i < q; ++i) {
        scanf("\n%c %c", &c[i], &dir[i]);
    }
    int ans = 0;
    for (int c = 0; c < max_c; ++c) {
        int l = -1, r = all[c].size();
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (go(all[c][mid]) == -1) {
                l = mid;
            } else {
                r = mid;
            }
        }
        int to = l;

        l = -1;
        r = all[c].size();
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (go(all[c][mid]) == n) {
                r = mid;
            } else {
                l = mid;
            }
        }
        ans += r - to - 1;
    }
    printf("%d\n", ans);
    return 0;
}
