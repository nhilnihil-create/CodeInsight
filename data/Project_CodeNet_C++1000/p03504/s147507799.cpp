#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<n; i++)
#define pb push_back
#define int long long
typedef tuple<int, int, int> T;

int N, C;
int s[100100], t[100100], c[100100];
int imos[100100];
int su[100100];

signed main() {
    cin >> N >> C;
    rep(i, N) cin >> s[i] >> t[i] >> c[i];
    for (int i=1; i<=C; i++) {
        rep(j, 100100) imos[j] = 0;
        rep(j, N) {
            if (c[j]==i) {
                imos[s[j]-1]++;
                imos[t[j]]--;
            }
        }
        for (int j=1; j<100100; j++) imos[j] += imos[j-1];
        rep(j, 100100) if (imos[j]>0) su[j]++;
    }
    int ans = 0;
    rep(i, 100100) ans = max(ans, su[i]);
    cout << ans << endl;
}