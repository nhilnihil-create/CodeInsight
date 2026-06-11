#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
#define bit(x) (1L << (x))
using ll = long long;
using namespace std;

template<typename T>
vector<T> make_v(size_t a,T b){return vector<T>(a,b);}
 
template<typename... Ts>
auto make_v(size_t a,Ts... ts){
        return vector<decltype(make_v(ts...))>(a,make_v(ts...));
}

int main() {
        ll n, k;
        cin >> n >> k;

        vector<ll> a(n);
        rep (i, n) cin >> a[i];

        ll x = 0;
        for (int i = 60; i >= 0; i--) {
                if (x + (1LL << i) > k) continue;
                int t = 0;
                rep (j, n) {
                        if ((1LL << i) & a[j]) {
                                t++;
                        }
                }

                if (t < n - t) {
                        x += 1LL << i;
                }
        }

        ll ans = 0;
        rep (i, n) ans += x ^ a[i];

        cout << ans << endl;

        return 0;
}
