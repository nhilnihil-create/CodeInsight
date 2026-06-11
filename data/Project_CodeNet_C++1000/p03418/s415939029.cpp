#include<bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl
typedef long long ll;
using namespace std;
int static fast = [](){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0); return 0;
}();
//a, b <= n
// a % b >= k
// a = b*x+k', k' >= k => b > k
// 2^10
int main() {
    ll n, k, ans = 0;
    cin >> n >> k;
    for(ll div= k+1; div <= n; div++) {
        ll rem = n % div;
        ll cnt = n/div;
        //[(0... k-1), k ... div] , 0 <= rem <= k-1
        //[0... k-1, (k ... )div] , k <= rem < div
        // remain pattern:
        //  1, 2, 3, ..div-1, div,div+1,
        // (1, 2, 3, ..div-1, 0) ,    1, 2,
        ll acc = k*cnt; // count remain = [0, k-1]
        if (k != 0) {
            acc += min(k-1, rem);
        }
        // cout << "div = " << div << ", cnt " << cnt << ", acc = " << (n-acc) << endl;
        ans += n - acc;
    }
    cout << ans << endl;
    return 0;
}


