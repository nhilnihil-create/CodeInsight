#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define prln(x) (cerr << #x << ' ' << x << endl)
#define pr(x) (cerr << #x << ' ' << x)
const int INF = 0x3f3f3f3f;
int n, q;
string s;
int k[75];

int main(){
    #ifdef LOCAL
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    cin >> n >> s >> q;
    for (int i = 0; i < q; ++i) {
        cin >> k[i];
    }

    for (int i = 0; i < q; ++i) {
        ll ans = 0, nd = 0, nm = 0, ndm = 0;
        for (int j = 0; j < n; ++j) {
            if (j - k[i] >= 0) {
                if (s[j - k[i]] == 'D') {
                    ndm -= nm;
                    --nd;
                }
                if (s[j - k[i]] == 'M') {
                    --nm;
                }
            }

            if (s[j] == 'D') {
                ++nd;
            }else if (s[j] == 'M') {
                ndm += nd;
                nm++;
            }else if (s[j] == 'C') {
                ans += ndm;
            }
        }
        cout << ans << endl;
    }
    return 0;
}