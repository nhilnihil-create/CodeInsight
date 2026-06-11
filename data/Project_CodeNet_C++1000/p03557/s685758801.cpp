#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <queue>
#include <unordered_map>

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;

using namespace std;

template<class T>
vector<T> make_vec(size_t a){
    return vector<T>(a);
}
template<class T, class... Ts>
auto make_vec(size_t a, Ts... ts){
    return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}

int main(){
    int n; cin >> n;
    vector<ll> a(n);
    vector<ll> b(n);
    vector<ll> c(n);
    rep(i, n) {
        cin >> a[i];
    }
    rep(i, n) {
        cin >> b[i];
    }
    rep(i, n) {
        cin >> c[i];
    }
    ll ans = 0;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());

    for(int i = 0 ; i < n; i++) {
        auto it = upper_bound(c.begin(), c.end(), b[i]);
        ll cnum = c.end() - it;
        auto it2 = lower_bound(a.begin(), a.end(), b[i]);
        ll anum = it2 - a.begin();
        if(cnum > 0 && anum > 0){
            // cout << cnum << " " << anum << endl;
            ans += cnum*anum;
            // cout << ans << endl;
        }
    }

    cout << ans << endl;
}
