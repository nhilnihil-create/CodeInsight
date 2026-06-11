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

        vector<ll> x(60, 0);
        rep (i, 60) {
                for (int j = 60; j >= 0; j--) {
                        if (x[i] + (1LL << j) > k) continue;
                        int t = 0;
                        rep (k, n) {
                                if ((1LL << j) & a[k]) {
                                        t++;
                                }
                        }

                        if ((j < i && t < n - t) || j >= i) {
                                x[i] += 1LL << j;
                        }
                }
        }

        vector<ll> r(60, 0);
        rep (i, 60) {
                rep (j, n) r[i] += x[i] ^ a[j];
        }

        cout << *max_element(r.begin(), r.end()) << endl;

        return 0;
}
