#include <bits/stdc++.h>
#define repl(i, l, r) for (int i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    rep(i, m) {
        int k;
        cin >> k;
        rep(j, k) {
            int s;
            cin >> s;
            s--;
            a[s] |= 1 << i;
        }
    }
    int p = 0;
    rep(i, m) {
        int x;
        cin >> x;
        p |= x << i;
    }
    int ans = 0;
    for(int s = 0; s < (1 << n); s++) {
        int t = 0;
        rep(i, n) {
            if(s >> i & 1) {
                t ^= a[i];
            }
        }
        if(t == p) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
