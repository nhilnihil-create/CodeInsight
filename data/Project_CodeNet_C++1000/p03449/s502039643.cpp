#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<n; i++)
#define pb push_back
#define int long long

int N;
int acc1[110], acc2[110];

signed main() {
    cin.tie(0); ios::sync_with_stdio(false);
    cin >> N;
    rep(i, N) {
        int A; cin >> A;
        acc1[i+1] = acc1[i]+A;
    }
    rep(i, N) {
        int A; cin >> A;
        acc2[i+1] = acc2[i]+A;
    }
    int ans = 0;
    rep(i, N) ans = max(ans, acc1[i+1]+acc2[N]-acc2[i]);
    cout << ans << endl;
}