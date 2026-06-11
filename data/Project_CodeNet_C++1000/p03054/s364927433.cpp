#include <iostream>
#include <algorithm>
#include <string>
#define flush fflush(stdout)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int mod = 1e9 + 7, INF = 1e9;


int main(void) {
    int h, w, n, si, sj, i, pi, pj;
    string s, t;

    scanf("%d%d%d%d%d", &h, &w, &n, &si, &sj);
    cin >> s >> t;
    
    pj = sj;
    for (i = 0; i < n; i++) {
        if (s[i] == 'L') pj--;
        if (pj == 0) {
            printf("NO\n");
            return 0;
        }
        if (t[i] == 'R') {
            pj = min(w, pj + 1);
        }
    }

    pj = sj;
    for (i = 0; i < n; i++) {
        if (s[i] == 'R') pj++;
        if (pj == w + 1) {
            printf("NO\n");
            return 0;
        }
        if (t[i] == 'L') {
            pj = max(1, pj - 1);
        }
    }

    pi = si;
    for (i = 0; i < n; i++) {
        if (s[i] == 'U') pi--;
        if (pi == 0) {
            printf("NO\n");
            return 0;
        }
        if (t[i] == 'D') {
            pi = min(h, pi + 1);
        }
    }

    pi = si;
    for (i = 0; i < n; i++) {
        if (s[i] == 'D') pi++;
        if (pi == h + 1) {
            printf("NO\n");
            return 0;
        }
        if (t[i] == 'U') {
            pi = max(1, pi - 1);
        }
    }

    printf("YES\n");

    return 0;
}