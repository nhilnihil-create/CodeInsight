#include <bits/stdc++.h>
using namespace std;

#define int long long
struct Fast {Fast(){cin.tie(0);ios::sync_with_stdio(0);}} fast;
using intpair = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, n, m) for (int i = (int)(n); i <= (int)(m); i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define rALL(obj) (obj).rbegin(), (obj).rend()
#define ceiv(a, b) ((int)((a) + (b) - 1)/(int)(b))

signed main() {
    int n, T;
    cin >> n >> T;
    
    int ans = INT_MAX;
    rep(i,n){
        int a, t;
        cin >> a >> t;
        if(t > T) continue;
        ans = min(a, ans);
    }
    
    if(ans != INT_MAX){
        cout << ans << endl;
    }else{
        cout << "TLE" << endl;
    }
}