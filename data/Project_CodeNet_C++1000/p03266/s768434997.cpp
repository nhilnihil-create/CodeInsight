#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); ++i)
#define REP(i, d, n) for(int i=(d); i<(n); ++i)
#define all(v) v.begin(), v.end()
using ll = long long;
using P = pair<int, int>;
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

int main() {

    int n, k;
    cin >> n >> k;

    ll x = 0;
    ll y = 0;
    for(int i=1; i<=n; i++){
        if(i % k == 0){
            x++;
        }
        if(i % k == k / 2){
            y++;
        }
    }
    ll ans = x * x * x;
    if(k % 2 == 0){
        ans += y * y * y;
    }

    cout << ans << endl;

    return 0;
}