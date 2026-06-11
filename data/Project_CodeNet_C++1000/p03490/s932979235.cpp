#include "bits/stdc++.h"
using namespace std;

#define FOR(i,a,b) for(int (i)=(a);i<(int)(b);i++)
#define rep(i,n) FOR(i,0,n)
#define mset(a,x) memset(a,x,sizeof(a))

char buf[114514];
int x, y;

bool dpx[8000][16010];
bool dpy[8000][16010];

int main() {
    mset(dpx, 0); mset(dpy, 0);
    scanf("%s", buf);
    scanf("%d%d", &x, &y);
    string s = buf;
    s += "T";

    vector<int> dx, dy;
    bool b = 0;
    int cnt = 0;
    for (auto&& c : s) {
        cnt += (c == 'F');
        if (c == 'T') {
            if (!b) dx.push_back(cnt);
            else dy.push_back(cnt);
            cnt = 0;
            b ^= 1;
        }
    }

    int n = dx.size(), m = dy.size();
    dpx[0][8000] = dpx[1][dx[0] + 8000] = 1;
    FOR(i, 1, n) rep(px, 16001) if (dpx[i][px]) {
        int j = px + dx[i];
        int k = px - dx[i];
        dpx[i + 1][j] = dpx[i + 1][k] = 1;
    }

    dpy[0][8000] = 1;
    rep(i, m) rep(py, 16001) if (dpy[i][py]) {
        int j = py + dy[i];
        int k = py - dy[i];
        dpy[i + 1][j] = dpy[i + 1][k] = 1;
    }

    cout << (dpx[n][x + 8000] && dpy[m][y + 8000] ? "Yes" : "No") << endl;
    return 0;
}