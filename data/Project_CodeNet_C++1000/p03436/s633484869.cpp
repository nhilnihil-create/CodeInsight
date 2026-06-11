#include <iostream>
#include <vector>
#include <queue>
#include<map>
#include<algorithm>
#include<set>
#include<iomanip>
#define rep(i,n) for(int i = 0;i < n;i++)
#define req(i,n) for(int i = 1; i<=n;i++)
#define ALL(a) a.begin(),a.end()
#define PI  acos(-1)
using namespace std;
template<typename A, size_t N, typename T>
void Fill(A(&array)[N], const T & val) {
    std::fill((T*)array, (T*)(array + N), val);
}
typedef long long int ll;
typedef long double ld;
int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
struct Corr {
    int x, y, depth;
};
int main() {
    int h, w,sum=0; cin >> h >> w;
    vector<string> G(h);
    rep(i, h) {
        cin >> G[i];
        rep(j, w) {
            if (G[i][j] == '#') sum++;
        }
    }
    vector<vector<int>> mp(h, vector<int>(w, 1e9));
    mp[0][0] = 0;
    queue<Corr> q;q.push({ 0,0,1 });
    while (!q.empty()) {
        Corr now = q.front(); q.pop();
        rep(i, 4) {
            int nx = now.x + dx[i], ny = now.y + dy[i];
            if (nx < 0 || ny < 0 || nx >= w || ny >= h) continue;
            if (mp[ny][nx] != 1e9||G[ny][nx]=='#')continue;
            mp[ny][nx] = now.depth + 1;
            q.push({ nx,ny,now.depth + 1 });
        }
    }if (mp[h - 1][w - 1] == 1e9) cout << -1 << endl;
    else cout << h * w - mp[h - 1][w - 1]-sum << endl;
}