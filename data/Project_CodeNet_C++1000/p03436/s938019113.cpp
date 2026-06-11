#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>
#include <algorithm>
#include <complex>
#include <array>
#include <iomanip>
using namespace std;

#define REP(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
#define FORR(i,a,b) for (int i=a; i>=b; --i)
#define ALL(c) (c).begin(), (c).end()

typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<long double> VD;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef vector<VD> VVD;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;

template<typename T> void chmin(T &a, T b) { if (a > b) a = b; }
template<typename T> void chmax(T &a, T b) { if (a < b) a = b; }

int in() { int x; scanf("%d", &x); return x; }
ll lin() { ll x; scanf("%lld", &x); return x; }
#define INF 1LL<<60

int main() {
    int H, W;
    cin >> H >> W;
    vector< vector<int> > map(H, vector<int>(W, 0));
    vector< vector<P> > prev(H, vector<P>(W));
    REP(i, H) {
        string s;
        cin >> s;
        REP(j, W) {
            if(s[j] == '#') map[i][j] = 1;
        }
    }

    vector< vector<int> > dist(H, vector<int>(W, -1));
    queue<P> que;
    que.push(make_pair(0, 0));
    dist[0][0] = 0;

    while(!que.empty()) {
        P cur = que.front();
        que.pop();

        int x_now = cur.first, y_now = cur.second;
        for(int x = max(0, x_now - 1); x <= min(W-1, x_now + 1); ++x)
            for(int y = max(0, y_now - 1); y <= min(H-1, y_now + 1); ++y) {
                if(x == x_now && y == y_now) continue;
                if(x != x_now && y != y_now) continue;
                if(map[y][x] == 1) continue;
                if(dist[y][x] > 0) continue;
                dist[y][x] = dist[y_now][x_now] + 1;
                prev[y][x] = cur;
                que.push(make_pair(x, y));
            }
    }

    vector<P> path;
    path.push_back(make_pair(W-1, H-1));

    P cur = make_pair(W-1, H-1);
    while(cur.first != 0 || cur.second != 0) {
        cur = prev[cur.second][cur.first];
        path.push_back(cur);
    }

    // reverse(ALL(path));
    // REP(i, path.size()) {
    //     cerr << "x: " << path[i].first << " y: " << path[i].second << endl;
    // }
    if(dist[H-1][W-1] == -1) {
        cout << -1 << endl;
        return 0;
    }
    sort(ALL(path));

    int ans = 0;
    REP(i, H)
        REP(j, W) {
            P cand = make_pair(j, i);
            bool flag = true;
            for(P node: path) {
                if(node.second == cand.second && node.first == cand.first)
                    flag = false;
            }
            if(map[i][j] == 1) flag = false;
            if(flag) ans++;
        }
    cout << ans << endl;
    return 0;
}