#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll n;
    double t, a;
    cin >> n >> t >> a;
    double ans = 0, mn = 1e18;
    rep(i, 0, n){
        double h; cin >> h;
        if(mn > abs(a - (t - 0.006 * h))) {
            mn = abs(a - (t - 0.006 * h));
            ans = i+1;
        }
    }
    cout << ans << endl;
    return 0;
}