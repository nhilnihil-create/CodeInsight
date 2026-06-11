//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
using namespace std;
using ll = int64_t;
using vi = vector<ll>;
using vvi = vector<vi>;

int main() {
    int n;
    ll h;
    cin >> n >> h;
    vi a(n), b(n);
    rep(i, n) {
        cin >> a[i] >> b[i];
    }

    sort(a.rbegin(), a.rend());
    sort(b.begin(), b.end());

    ll sum = 0LL;

    vi::iterator itr = upper_bound(b.begin(), b.end(), a[0]);
    ll ans = 0LL;
    for(vi::iterator iitr = b.end()-1; iitr+1 != itr; --iitr) {
        if(h > (sum += *iitr)) {
            ++ans;
        } else {
            ++ans;
            break;
        }
    }

    if(sum < h) {
        ans += (h-sum+a[0]-1)/a[0];
    }

    cout << ans << endl;
    
}