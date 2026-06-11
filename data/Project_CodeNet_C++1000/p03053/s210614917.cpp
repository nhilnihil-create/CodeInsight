#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <functional>
#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
using namespace std;
#define ll long long int
#define rep(i,n) for( int i = 0; i < n; i++ )
#define rrep(i,n) for( int i = n; i >= 0; i-- )
#define REP(i,s,t) for( int i = s; i <= t; i++ )
#define RREP(i,s,t) for( int i = s; i >= t; i-- )
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define INF 2000000000
#define mod 1000000007
#define INF2 1000000000000000000
typedef pair<int, int> P;
typedef pair<int, P> PP;
int d[1010][1010];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int H, W;
    cin >> H >> W;
    string S[1010];
    rep(i, H) cin >> S[i];
    priority_queue<PP, vector<PP>, greater<PP>> que;
    rep(i, H) rep(j, W) d[i][j] = INF;
    rep(i, H)  {
        rep(j, W) {
            if(S[i][j] == '#') {
                que.push({0, {i, j}});
                d[i][j] = 0;
            }
        }
    }
    int ans = 0;
    while(que.size()) {
        PP p = que.top(); que.pop();
        int x = p.second.first;
        int y = p.second.second;
        if(p.first > d[x][y]) continue;
        rep(k, 4) {
            int xx = x + dx[k];
            int yy = y + dy[k];
            if(xx < 0 || xx >= H || y < 0 || y >= W) continue;
            if(d[xx][yy] > p.first + 1) {
                d[xx][yy] = p.first + 1;
                ans = max(ans, d[xx][yy]);
                que.push({d[xx][yy], {xx, yy}});
            }
        }
    }
    cout << ans << endl;



    return 0;
}
