#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1000000000;
const int MOD = MM + 7;
const int MAX = 510000;
#define rep(i, n) for(ll i=0; i<n; i++)
#define Rep(i, j, n) for(ll i=j; i<n; i++)
#define all(vec) vec.begin(), vec.end()
template<class T> inline bool chmin(T& a, T b) {if(a > b) {a = b; return true;} return false;}
template<class T> inline bool chmax(T& a, T b) {if(a < b) {a = b; return true;} return false;}
const ll INF = 1LL << 60;
const double pi = acos(-1.0);

int main() {
    ll k, a, b; cin >> k >> a >> b;
    if(b <= a+2) {
        cout << k+1 << endl;
        return 0;
    }
    if(k <= a) {
        cout << k+1 << endl;
        return 0;
    }
    if(a&1) {
        if(k&1) cout << a+1 + (k-a)/2 * (b-a) << endl;
        else cout << a + (k-a+1)/2 * (b-a) << endl;
    }
    else {
        if(k&1) cout << a + (k-a+1)/2 * (b-a) << endl;
        else cout << a+1 + (k-a)/2 * (b-a) << endl;
    }
}