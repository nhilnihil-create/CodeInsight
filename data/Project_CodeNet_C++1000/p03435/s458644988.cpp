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
    vector<vector<int>> v(3, vector<int>(3));
    rep(i, 3) rep(j, 3) cin >> v[i][j];
    rep(i, 101) {
        rep(j, 101) {
            rep(k, 101) {
                int b1 = v[0][0] - i, b2 = v[0][1] - i, b3 = v[0][2] - i;
                if(b1 < 0 || b2 < 0 || b3 < 0) continue;
                if(j + b1 != v[1][0] || j + b2 != v[1][1] || j + b3 != v[1][2]) continue;
                if(k + b1 != v[2][0] || k + b2 != v[2][1] || k + b3 != v[2][2]) continue;
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
}