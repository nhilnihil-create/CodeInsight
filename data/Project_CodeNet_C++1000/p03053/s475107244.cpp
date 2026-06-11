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






int main() {
    int h, w;
    cin >> h >> w;
    vector<vector<int>> a(h, vector<int>(w, 0));
    queue<P> Q;
    rep (i, h) {
        string s;
        cin >> s;
        rep (j, w) {
            if (s[j] == '#') {
                a[i][j] = 1;
                Q.push(make_pair(i, j));
            }
        }
    }
    int ans = 0;
    vector<int> dx = {0, 0, 1, -1};
    vector<int> dy = {1, -1, 0, 0};
    while (!Q.empty()) {
        ans++;
        vector<P> next;
        while (Q.size()) {
            P f = Q.front();
            Q.pop();
            int y = f.first;
            int x = f.second;
            rep (i, 4) {
                int newy = y + dy[i];
                int newx = x + dx[i];
                if (newy < 0 || h <= newy) continue;
                if (newx < 0 || w <= newx) continue;
                if (a[newy][newx] == 1) continue;
                next.push_back(make_pair(newy, newx));
                a[newy][newx] = 1;
            }
        }
        rep (i, next.size()) {
            Q.push(next[i]);
        }
    }
    cout << ans - 1 << endl;
}

