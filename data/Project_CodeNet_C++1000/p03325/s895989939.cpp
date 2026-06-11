#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<n; i++)
#define pb push_back
#define int long long

int N;

signed main() {
    cin.tie(0); ios::sync_with_stdio(false);
    cin >> N;
    int ans = 0;
    rep(i, N) {
        int ai; cin >> ai;
        int cnt = 0;
        while (ai%2==0) {
            ai /= 2;
            cnt++;
        }
        ans += cnt;
    }
    cout << ans << endl;
}