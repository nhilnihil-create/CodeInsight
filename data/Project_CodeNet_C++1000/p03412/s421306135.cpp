#include <bits/stdc++.h>
#define For(i, a, b) for(int (i)=(a); (i)<(b); (i)++)
#define rFor(i, a, b) for(int (i)=(a)-1; (i)>=(b); (i)--)
#define rep(i, n) For((i), 0, (n))
#define rrep(i, n) rFor((i), (n), 0)
using namespace std;
typedef long long lint;

int main(){
    int n; cin >> n;
    lint a[n], b[n];
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    int ans = 0;
    rrep(i, 30){
        rep(j, n) a[j] %= (1LL<<(i+1)), b[j] %= (1LL<<(i+1));
        sort(b, b+n);
        rep(j, n){
            if(a[j] <= (1LL<<i)){
                auto l = lower_bound(b, b+n, (1LL<<i) - a[j]);
                auto r = lower_bound(b, b+n, (1LL<<(i+1)) - a[j]);
                ans ^= ((r-l)%2) << i;
            }
            else{
                auto r = lower_bound(b, b+n, (1LL<<(i+1)) - a[j]);
                auto l = lower_bound(b, b+n, (1LL<<(i+1)) + (1LL<<i) - a[j]);
                ans ^= ((r-b) + ((b+n)-l))%2 << i;
            }
        }
    }
    cout << ans << endl;
}