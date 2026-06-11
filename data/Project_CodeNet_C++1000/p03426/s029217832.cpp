#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> VI;

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define all(x) (x).begin(),(x).end()

const int mod = 1e9 + 7;

int main() {
    int h, w, d;
    cin >> h >> w >> d;
    vector<P> place(h * w);
    rep (i, h) {
        vector<int> x(w);
        rep (j, w) {
            cin >> x[j];
            x[j]--;
        }
        rep (j, w) {
            place[x[j]] = make_pair(i, j);
        }
    }
    vector<vector<int>> dist(d);
    rep (i, d) {
        dist[i].push_back(0);
    }
    rep (i, h * w) {
        if (i / d == 0) {
            dist[i % d].push_back(0);
        } else {
            int x = abs(place[i].first - place[i-d].first);
            int y = abs(place[i].second - place[i-d].second);
            dist[i % d].push_back(x + y);
        }
    }
    rep (i, d) {
        rep (j, dist[i].size() - 1) {
            dist[i][j+1] += dist[i][j];
        }
    }
    int q;
    cin >> q;
    rep (i, q) {
        int start, goal;
        cin >> start >> goal;
        if (start == goal) {
            cout << 0 << endl;
            continue;
        }
        start--; goal--;
        int row = start % d;
        start /= d;
        goal /= d;
        cout << dist[row][goal+1] - dist[row][start+1] << endl;
    }
}


