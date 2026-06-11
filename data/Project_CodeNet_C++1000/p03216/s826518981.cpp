#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <algorithm>
#include <cstdio>
#include <iomanip>
#include <queue>
#include <deque>
#include <stack>
#include <fstream>
#include <cmath>
#include <random>
#include <complex>
#include <functional>

#define ll int64_t
#define Rep(i, n) for (ll i = 0; i < n; i++)
using namespace std;
typedef vector<ll> vec;
typedef vector<vec> mat;

const ll inf = 1LL << 60;

template<class T> inline void chmin(T& a, T b) {
    if (a > b) {
        a = b;
    }
}
template<class T> inline void chmax(T& a, T b) {
    if (a < b) {
        a = b;
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, Q;
    string S;
    cin >> N >> S >> Q;

    while (Q--) {
        ll k;
        cin >> k;
        ll d = 0, dm = 0, m = 0, ans = 0;
        Rep (i, k) {
            if (S[i] == 'D') d++;
            if (S[i] == 'M') {
                dm += d;
                m++;
            }
            if (S[i] == 'C') {
                ans += dm;
            }
            // cerr << i << " " << d << " " << m << " " << dm << "\n";
        }

        Rep (i, N-k) {
            if (S[i] == 'D') {
                d--;
                dm -= m;
            }
            if (S[i] == 'M') {
                m--;
            }

            if (S[i+k] == 'D') d++;
            if (S[i+k] == 'M') {
                dm += d;
                m++;
            }
            if (S[i+k] == 'C') {
                ans += dm;
            }
            // cout << i << " " << d << " " << m << " " << dm << "\n";            
        }

        cout << ans << "\n";
    }

}