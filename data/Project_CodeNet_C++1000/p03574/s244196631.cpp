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

int dh[8] = {0, 0, 1, 1, 1, -1, -1, -1};
int dw[8] = {1, -1, 0, 1, -1, 0, 1, -1};

int main() {
    int h, w; cin >> h >> w;
    vector<vector<char>> v(h, vector<char>(w));
    rep(i, h) rep(j, w) cin >> v[i][j];
    vector<vector<int>> ans(h, vector<int>(w, 0));
    rep(i, h) {
        rep(j, w) {
            if(v[i][j] == '#') {
                rep(k, 8){
                    int nh = i + dh[k];
                    int nw = j + dw[k];
                    if(nh < 0 || h <= nh || nw < 0 || w <= nw) continue;
                    ans[nh][nw]++;
                }
            }
        }
    }
    rep(i, h) {
        rep(j, w) {
            if(v[i][j] == '#') cout << '#';
            else cout << ans[i][j];
        }
        cout << endl;
    }
}