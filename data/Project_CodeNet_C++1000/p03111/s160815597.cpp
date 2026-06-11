#include <bits/stdc++.h>
using namespace std;

//#define int long long
using ll = long long;
using ld = long double;
using intpair = pair<int, int>;
const int MOD = 1e9 + 7;
inline int mod (ll a, int m = MOD) { return (a % m + m) % m; }
//struct Fast {Fast(){cin.tie(0);ios::sync_with_stdio(0);}} fast;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, n, m) for (int i = (int)(n); i <= (int)(m); i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define rALL(obj) (obj).rbegin(), (obj).rend()
#define ceiv(a, b) ((ll)((a) + (b) - 1)/(ll)(b))

signed main() {
    int n, a[3];
    cin >> n >> a[0] >> a[1] >> a[2];
    
    int limit = 1;
    rep(i,n) limit *= 4;
    
    vector<int> l(n);
    rep(i,n) cin >> l[i];
    
    int make[4], times[4];
    
    int ans = INT_MAX;
    rep(i,limit){
        rep(j,4){
            make[j] = 0;
            times[j] = -1;
        }
        int k = i;
        rep(j,n){
            int idx = k % 4;
            times[idx]++;
            make[idx] += l[j];
            k /= 4;
        }
        if(times[0] == -1 || times[1] == -1 || times[2] == -1){
            continue;
        }
        int t = 0;
        rep(i,3){
            t += times[i] * 10;
            t += abs(a[i] - make[i]);
        }
        ans = min(t, ans);
    }
    
    cout << ans << endl;
}