#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<n; i++)
#define pb push_back
#define int long long

int N, K;
 
signed main() {
    cin.tie(0); ios::sync_with_stdio(false);
    cin >> N >> K;
    int ans = 1000000;
    rep(i, N+1) {
        int ans_cand = 1;
        rep(j, i) ans_cand *= 2;
        ans_cand += (N-i)*K;
        ans = min(ans, ans_cand);
    }
    cout << ans << endl;
}