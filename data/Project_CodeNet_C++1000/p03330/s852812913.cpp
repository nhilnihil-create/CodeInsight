#include <iostream>
#include <set>
#include <vector>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

const int N = 100009;
const long long INF = 1LL << 60;
const long long MOD = 1000000007;

int main() {
    int n, c;
    cin >> n >> c;
    Graph D(c);
    rep(i, c) rep(j, c) {
        int d;
        cin >> d;
        D[i].push_back(d);
    }
    
    vector < vector<long long>> iwakan(c, vector<long long>(3, 0));
    rep(i, n) rep(j, n) {
        int g;
        cin >> g;
        rep(k, c)
            iwakan[k][(i + j) % 3] += D[g-1][k];
    }

    long long ans = -1;
    rep(i0, c) {
        rep(i1, c) {
            if (i0 == i1) continue;
            rep(i2, c) {
                if (i0 == i2 || i1 == i2) continue;
                long long temp = 0;
                temp += iwakan[i0][0];
                temp += iwakan[i1][1];
                temp += iwakan[i2][2];
                if (ans<0 || ans>temp) ans = temp;
                //cout << i0 << " " << i1 << " " << i2 << endl;
            }
        }
    }

    cout << ans << endl;
}