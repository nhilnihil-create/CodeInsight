#include <bits/stdc++.h>
#define rep(i, a, n) for(int i = a; i < n; i++)
#define REP(i, n) rep(i, 0, n)
#define repb(i, a, b) for(int i = a; i >= b; i--)
#define all(a) a.begin(), a.end()
#define int long long
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
typedef pair<int, int> P;
const int mod = 1000000007;
const int INF = 1e12;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    rep(i, 0, n){
        cin >> a[i];
    } 
    rep(i, 0, n){
        cin >> b[i];
    }
    int ans = 0;
    rep(i, 0, 30){
        vector<int> bb(n);
        rep(j, 0, n){
            bb[j] = b[j] % (1LL << (i + 1));
        }
        int cnt = 0;
        sort(all(bb));
        rep(j, 0, n){
            int aa = a[j] % (1LL << (i + 1));
            cnt += bb.end() - lower_bound(all(bb), (3 << i) - aa);
            cnt += upper_bound(all(bb), (1LL << (i + 1)  ) - 1 - aa) - lower_bound(all(bb), (1LL << i) - aa);
        }
        ans |= (cnt % 2) << i;
    }
    cout << ans << endl;
}