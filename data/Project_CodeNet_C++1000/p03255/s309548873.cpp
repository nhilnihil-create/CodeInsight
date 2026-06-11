#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
 
int n;
ll x, ans = (ll)9e18, a[200005];
 
int main() {
    cin >> n >> x;
    for(int i = 1; i <= n; ++i) cin >> a[i], a[i] += a[i-1];
    for(int k = 1; k <= n; ++k) {
        ll coef = 3LL, sum = 0;
        for(int i = n; i >= 1; i -= k) {
            sum += (a[i]-a[max(0, i-k)])*max(coef, 5LL), coef += 2;
            if(sum >= ans) break; //防爆long long
        }
        ans = min(ans, sum+(k+n)*x);
    }
    cout << ans << endl;
    return 0;
}