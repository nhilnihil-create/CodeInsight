#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<n; i++)
#define pb push_back
#define int long long

int N, M;

signed main() {
    cin.tie(0); ios::sync_with_stdio(false);
    cin >> N >> M;
    int ans = 0;
    for (int i=1; i*i<=M; i++) {
        if (M%i==0) {
            if (i*N<=M) ans = max(ans, i);
            if (i!=M/i) {
                int j = M/i;
                if (j*N<=M) ans = max(ans, j);
            }
        }
    }
    cout << ans << endl;
}