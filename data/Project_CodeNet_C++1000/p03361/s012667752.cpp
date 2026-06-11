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

int main() {
    int h, w; cin >> h >> w;
    vector<vector<char>> s(h+2, vector<char>(w+2));
    rep(i, h+2) {
        rep(j, w+2) {
            if(i == 0 || i == h+1 || j == 0 || j == w+1) s[i][j] = '.';
            else {
                cin >> s[i][j];
            }
        }
    }
    Rep(i, 1, h+1) {
        Rep(j, 1, w+1) {
            if(s[i][j] == '#' && s[i-1][j] != '#' && s[i+1][j] != '#' && s[i][j-1] != '#' && s[i][j+1] != '#') {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
}