#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(ll i = 0, i##_len = (n); i < i##_len; i++)
#define reps(i, s, n) for(ll i = (s), i##_len = (n); i < i##_len; i++)
#define rrep(i, n) for(int i = (n) - 1; i >= 0; i--)
#define rreps(i, e, n) for(int i = (n) - 1; i >= (e); i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define uniq(x) (x).erase(unique((x).begin(), (x).end()), (x).end())

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    ll n, k;
    cin >> n >> k;
    ll ans = 0;
    
    if (k == 0) {
        ans = n * n;
    }
    else {
        reps(b, k + 1, n + 1) {
            rep(x, (n - k) / b + 1) {
                ll l = x * b + k;
                ll r = min(n, (x + 1) * b - 1);
                
                if (l > r) {
                    break;
                }
                
                ans += r - l + 1;
            }
        }
    }
    
    cout << ans << endl;
    return 0;
}
