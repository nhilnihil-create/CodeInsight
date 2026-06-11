#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = std::pair<int, int>;

#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define pb push_back
const int mn = 1e6 + 5;

int n, q;
char s[mn];

ll query(int k) {
    ll dmCnt = 0, ans = 0;
    ll cntd = 0, cntm = 0;
    for (int i = 1; i <= n; i++) {
        if (i - k >= 1) {
            if (s[i - k] == 'D') {
                cntd--;
                dmCnt-=cntm;
            }
            if (s[i - k] == 'M') {
                cntm--;
            }
        }
        if (s[i] == 'D') {
            cntd++;
        }
        if (s[i] == 'M') {
            cntm++;
            dmCnt += cntd;
        }
        if (s[i] == 'C') {
            ans += dmCnt;
        }
    }
    return ans;
}

int main() {
#ifdef trote
    freopen("../1.txt", "r", stdin);
#endif

    scanf("%d", &n);
    scanf("%s", s + 1);
    scanf("%d", &q);
    while (q--) {
        int k;
        scanf("%d", &k);
        printf("%lld\n", query(k));
    }
    return 0;
}