//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using P = pair<int, int>;
using vs = vector<string>;
using vi = vector<int>;
using vvi = vector<vi>;
const int INF = 100010001;
const ll LINF = (ll)INF*INF*10;

int main() {
    int n, c;
    cin >> n >> c;
    vvi d(c, vi(c));
    rep(i, c) {
        rep(j, c) {
            cin >> d[i][j];
        }
    }
    vvi ch(3, vi(c));
    rep(i, n) {
        rep(j, n) {
            int dd;
            cin >> dd;
            dd--;
            ch[(i+j)%3][dd]++;
        }
    }

    vector<vector<P> > iwa(3, vector<P>(c));
    rep(i, 3) {
        rep(j, c) {
            int num = 0;
            rep(k, c) {
                num += d[k][j] * ch[i][k];
            }
            iwa[i][j] = P(num, j);
        }
    }

    int ans = INF*10;
    rep(i, c) {
        rep(j, c) {
            rep(k, c) {
                if(iwa[0][i].second != iwa[1][j].second && iwa[1][j].second != iwa[2][k].second && iwa[2][k].second != iwa[0][i].second) {
                    ans = min(ans, iwa[0][i].first + iwa[1][j].first + iwa[2][k].first);
                }
            }
        }
    }

    cout << ans << endl;
}