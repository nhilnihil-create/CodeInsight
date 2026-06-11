#include <iostream> 
#include<vector>
#include<algorithm>
#include<map>
#include<iomanip>
#include<set>
#include<queue>
#include<deque>
#include<iomanip>
#include<sstream>
#include<cmath>
#include<tuple>
#include<bitset>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define req(i,n) for(int i = 1;i <=  n; i++)
#define rrep(i,n) for(int i = n -1;i >= 0;i--)
#define ALL(obj) begin(obj), end(obj)
typedef long long int ll;
typedef long double ld;
const ll INF = pow(10,15);
int k,x,m, n, h,r,c=0,w; string s;
const ll MOD= 1000000007;
const ld PI = acos(-1);
template<typename A, size_t N, typename T>
void Fill(A(&array)[N], const T & val) {
    std::fill((T*)array, (T*)(array + N), val);
} 
struct Corr {
    int x;
    int y;
    int depth;
};
queue<Corr> q; vector<vector<char>> v;
vector<vector<bool>> ispassed;
vector<vector<int>> dist;
void bfs () {
    int dx[8] = { 1, 0, -1, 0 };
    int dy[8] = { 0, 1, 0, -1 };
    while (!q.empty()) {
        Corr now = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int nextx = now.x + dx[i];
            int nexty = now.y + dy[i];
            if (nextx >= w || nextx < 0) continue;
            if (nexty >= h || nexty < 0) continue;
            if (dist[nexty][nextx] != -1) continue;
            dist[nexty][nextx] = now.depth + 1;
            Corr next = { nextx, nexty, now.depth + 1 };
            q.push(next);
        }
    }
}
int main() {
    cin >> h >> w; v.resize(h, vector<char>(w));
    dist.resize(h, vector<int>(w, -1));
    rep(i, h) {
        rep(j, w) {
            cin >> v[i][j];
            if (v[i][j] == '#') {
                dist[i][j] = 0;
                Corr st = { j,i,0 };
                q.push(st);
            }
        }
    }
    bfs();
    rep(i, h) rep(j, w) c = max(dist[i][j], c);
    cout << c << endl;
}