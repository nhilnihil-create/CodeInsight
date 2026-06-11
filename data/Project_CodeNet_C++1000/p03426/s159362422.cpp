#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#include<deque>
#include<map>
#include<bitset>
using namespace std;
typedef long long ll;

#define rep(i, n) for(int i = 0;i < (n);i++)
#define repr(i, n) for(int i = (n);i >= 0;i--)
#define repf(i, m, n) for(int i = (m);i < (n);i++)

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1;} return 0;}
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1;} return 0;}
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
//////////////////////////////////////////////////


int main() {
    int h, w, d;
    cin >> h >> w >> d;

    vector<vector<int>> a(h,vector<int>(w));
    typedef pair<int, int> P;
    map<int, P> m;
    rep(i,h) rep(j,w) {
        cin >> a[i][j];
        m[a[i][j]] = P(i,j);
    }

    vector<int> sum(h*w+1);
    repf(i,1,h*w+1) {
        int pre = i-d;
        if (pre > 0) {
            int hp = abs(m[i].first-m[pre].first) + abs(m[i].second-m[pre].second);
            sum[i] = sum[pre] + hp;
        }
    }

    int q; cin >> q;
    vector<int> l(q), r(q);
    rep(i,q) cin >> l[i] >> r[i];
    rep(i,q) {
        if (l[i]-d > 0) {
            cout << sum[r[i]] - sum[l[i]] << endl;
        } else {
            cout << sum[r[i]] << endl;
        }
    }
    return 0;
}