#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vs = vector<string>;
using vll = vector<long long>;
using vvi = vector<vector<int>>;
template<class T> inline bool chmax(T &a, T b) { if (a<b) {a=b; return 1;} return 0;}
template<class T> inline bool chmin(T &a, T b) { if (b<a) {a=b; return 1;} return 0;}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vi a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];

    vi diff(n);
    rep(i, n) diff[i] = a[i] - b[i];
    sort(diff.begin(), diff.end());
    int neg = lower_bound(diff.begin(), diff.end(), 0) - diff.begin();
    ll neg_sum = 0;
    rep(i, neg) {
        neg_sum += diff[i];
    }
    int ans = neg;
    for (int i = n-1; i >= 0 ; --i) {
        if (neg_sum >= 0) {
            break;
        }
        if (diff[i] <= 0) {
            ans = -1;
            break;
        } else {
            neg_sum += diff[i];
            ans++;
        }
    }
    cout << ans << endl;
}