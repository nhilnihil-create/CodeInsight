#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<n; i++)
#define pb push_back
#define int long long

int N;
int h[110];

signed main() {
    cin.tie(0); ios::sync_with_stdio(false);
    cin >> N;
    rep(i, N) cin >> h[i];
    int ans = 0;
    while (true) {
        bool update = false;
        rep(i, N) {
            if (h[i]>0 && h[i+1]==0) ans++;
            if (h[i]>0) {
                h[i]--;
                update = true;
            }
        }
        if (!update) break;
    }
    cout << ans << endl;
}