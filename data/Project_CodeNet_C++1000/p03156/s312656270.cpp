#include <bits/stdc++.h>
#define FOR(i, a, n) for(ll i = (ll)a; i < (ll)n; i++)
#define rep(i, n) FOR(i, 0, n)
using namespace std;
typedef long long ll;

const ll mod = 1e9 + 7;

template <class T> inline bool chmax(T &a, const T &b) {
    if(a >= b) return false;
    a = b;
    return true;
}
template <class T> inline bool chmin(T &a, const T &b) {
    if(a <= b) return false;
    a = b;
    return true;
}

/*-------------------------------------------*/

int n, a, b, p, x, y, z;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n >> a >> b;
    rep(i, n) {
        cin >> p;
        if(p <= a)
            x++;
        else if(b < p)
            z++;
        else
            y++;
    }
    cout << min(min(x, y), z) << endl;
}