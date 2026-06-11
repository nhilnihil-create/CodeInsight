#include <bits/stdc++.h>
using namespace std;

typedef long lint;
typedef long long llint;
typedef pair<int, int> pint;
typedef pair<long long, long long> pllint;

// static const int MAX = 1e6;
// static const int NIL = -1;
// static const llint INF = 1<<21;
// static const llint MOD = 1e9 + 7;

bool compPair(const pint& arg1, const pint& arg2) { return arg1.first > arg2.first; }
template<class T> void chmax(T& a, T b) { if (a < b) { a = b; } }
template<class T> void chmin(T& a, T b) { if (a > b) { a = b; } }

vector<vector<char>> s;
vector<vector<int>> g;
int h, w;

int bfs(int sy, int sx) {
    queue<pint> q;
    q.push(make_pair(sy,sx));

    pint u;
    int ux, uy;
    g.at(0).at(0) = 0;
    while(!q.empty()) {
        u = q.front(); q.pop();
        uy = u.first;
        ux = u.second;
        if(uy-1>=0) {
            if(s.at(uy-1).at(ux)=='.'&&g.at(uy-1).at(ux)==-1) { 
                q.push(make_pair(uy-1, ux));
                g.at(uy-1).at(ux) = g.at(uy).at(ux) + 1;
            }
        }
        if(uy+1<h) {
            if(s.at(uy+1).at(ux)=='.'&&g.at(uy+1).at(ux)==-1) { 
                q.push(make_pair(uy+1, ux));
                g.at(uy+1).at(ux) = g.at(uy).at(ux) + 1;
            }
        }
        if(ux-1>=0) {
            if(s.at(uy).at(ux-1)=='.'&&g.at(uy).at(ux-1)==-1) { 
                q.push(make_pair(uy, ux-1));
                g.at(uy).at(ux-1) = g.at(uy).at(ux) + 1;
            }
        }
        if(ux+1<w) {
            if(s.at(uy).at(ux+1)=='.'&&g.at(uy).at(ux+1)==-1) { 
                q.push(make_pair(uy, ux+1));
                g.at(uy).at(ux+1) = g.at(uy).at(ux) + 1;
            }
        }
        if(uy==h-1&&ux==w-1) { 
            return g.at(h-1).at(w-1);
        }
    }
    return -1;
}

int main(void) {
    cin >> h >> w;

    int white = 0;
    string stmp;
    s.resize(h, vector<char>(w));
    g.resize(h, vector<int>(w,-1));
    for(int ih=0;ih<h;ih++) {
        for(int iw=0;iw<w;iw++) {
            cin >> s.at(ih).at(iw);
            if(s.at(ih).at(iw)=='.') white++;
        }
    }

    int ans, res;
    res = bfs(0, 0);
    if(res==-1) {
        cout << -1 << endl;
        return 0;
    }
    else {
        ans = white-res-1;
    }
    cout << ans << endl;
    return 0;
}

