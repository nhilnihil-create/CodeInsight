#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
#include <cmath>
#include <string>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rep01(i, n) for(int i = 0; i < (n) + 1; i++)
#define rep10(i, n) for(int i = 1; i < (n); i++)
#define rep11(i, n) for(int i = 1; i < (n) + 1; i++)
#define all(a) (a).begin(), (a).end()
typedef long long int ll;
typedef struct { int x; int y; } Pos;
using namespace std;

//ABC088D
const int dx[] = { 1,-1,0,0 }, dy[] = { 0,0,1,-1 };
int H, W;
int b = 0;
vector<vector<char>> s;
vector<vector<bool>> r;
vector<vector<int>> d;
queue<Pos> q;
int main()
{
    cin >> H >> W;
    s = vector<vector<char>>(W + 1, vector<char>(H + 1));
    r = vector<vector<bool>>(W + 1, vector<bool>(H + 1));
    d = vector<vector<int>>(W + 1, vector<int>(H + 1));
    rep11(y, H) rep11(x, W) {
        cin >> s[x][y];
        if (s[x][y] == '#') b++;
    }
    q.push(Pos{ 1, 1 });
    while (q.size() > 0) {
        Pos ref = q.front();
        q.pop();
        rep(i, 4) {
            int ckx = ref.x + dx[i];
            int cky = ref.y + dy[i];
            if (ckx <= 0 || ckx > W || cky <= 0 || cky > H) continue;
            if (r[ckx][cky]) continue;
            if (s[ckx][cky] == '#') continue;
            r[ckx][cky] = true;
            d[ckx][cky] = d[ref.x][ref.y] + 1;
            q.push(Pos{ ckx, cky });
        }
    }
    if(r[W][H])
        cout << H * W - b - d[W][H] - 1 << endl;
    else
        cout << -1 << endl;
    return 0;
}