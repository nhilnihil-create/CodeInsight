#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define ll long long
#define P pair<int,int>
#define fast_io ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
const int MOD = 1000000007;
const int INF = 2002002002;
const ll LLINF = 9009009009009009009;
using namespace std;

int main() {
    fast_io
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    rep(i,n) cin >> v[i];

    int ans = 0;
    rep(n_l, n+1) {
        rep(n_r, n+1) {
            if (n_l + n_r > n || n_l + n_r > k) break;
            priority_queue<int, vector<int>, greater<int>> neg_v;
            int total = 0;
            rep(i,n_l) {
                total += v[i];
                if (v[i] < 0) neg_v.push(v[i]);
            }
            rep(i,n_r) {
                int ind = n - 1 - i;
                total += v[ind];
                if (v[ind] < 0) neg_v.push(v[ind]);
            }
            int rest_k = k - n_l - n_r;
            while (rest_k > 0 && !neg_v.empty()) {
                total -= neg_v.top();
                neg_v.pop();
                rest_k--;
            }
            ans = max(ans, total);
        }
    }
    cout << ans << endl;
    return 0;
}