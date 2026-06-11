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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n[4];
    rep(i, 4) cin >> n[i];
    sort(n, n + 4);
    if(n[0] == 1 && n[1] == 4 && n[2] == 7 && n[3] == 9)
        cout << "YES\n";
    else
        cout << "NO\n";
}