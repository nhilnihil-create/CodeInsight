#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int h, w, n, sr, sc;

const char DIRECTIONS[4] = { 'U', 'D', 'L', 'R' };

int main() {
    string s, t;
    cin >> h >> w >> n >> sr >> sc >> s >> t;
    sr--;
    sc--;
    for (auto target: DIRECTIONS) {
        if (target == 'U') {
            int r = sr;
            for (int i = 0; i < n; i++) {
                if (s[i] == 'U') {
                    r--;
                    if (r < 0) {
                        printf("NO");
                        return 0;
                    }
                }
                if (t[i] == 'D' && r < h - 1) {
                    r++;
                }
            }
        } else if (target == 'D') {
            int r = sr;
            for (int i = 0; i < n; i++) {
                if (s[i] == 'D') {
                    r++;
                    if (r > h - 1) {
                        printf("NO");
                        return 0;
                    }
                }
                if (t[i] == 'U' && r > 0) {
                    r--;
                }
            }
        } else if (target == 'L') {
            int c = sc;
            for (int i = 0; i < n; i++) {
                if (s[i] == 'L') {
                    c--;
                    if (c < 0) {
                        printf("NO");
                        return 0;
                    }
                }
                if (t[i] == 'R' && c < w - 1) {
                    c++;
                }
            }
        } else if (target == 'R') {
            int c = sc;
            for (int i = 0; i < n; i++) {
                if (s[i] == 'R') {
                    c++;
                    if (c > w - 1) {
                        printf("NO");
                        return 0;
                    }
                }
                if (t[i] == 'L' && c > 0) {
                    c--;
                }
            }
        }
    }
    printf("YES");
    return 0;
}
