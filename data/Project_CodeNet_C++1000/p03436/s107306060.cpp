#include <bits/stdc++.h>
#include <vector>
# include <cstdint>
#define FOR(i,l,r) for(int i=(l);i<(r);++i)
#define RFOR(i,l,r) for(int i=(l);i>=(int)(r);i--)
#define rep(i,n)  FOR(i,0,n)
#define rrep(i,n)  RFOR(i,n-1,0)

using namespace std;
#define int long long
using ll = long long;
const int MX = 1e6;
const ll inf = 1e13;
const int mod = 1e9+7;
char g[100][100];
int a[100][100];
signed main() {
    int h,w;
    cin >> h >> w;
    int ans = h*w;
    FOR(i,1,h+1) {
        string s;
        cin >> s;
        FOR(j,1,w+1) {
            g[i][j]=s[j-1];
            if(g[i][j]=='#')ans--;
        }
    }
    queue<pair<pair<int,int>,int>> q;
    q.push({{1,1},1});
    a[1][1]=0;

    while(q.size()>0) {
        pair<pair<int,int>,int> now = q.front();
        int x = now.first.first;
        int y = now.first.second;
        int d = now.second;
        q.pop();
        if(a[x][y]>0) continue;
        a[x][y]=1;

        if(x==h&&y==w) {
            ans -= d;
            break;
        }
        if(g[x+1][y]=='.') {
            q.push({{x+1,y},d+1});
        }
        if(g[x-1][y]=='.') {
            q.push({{x-1,y},d+1});
        }
        if(g[x][y+1]=='.') {
            q.push({{x,y+1},d+1});
        }
        if(g[x][y-1]=='.') {
            q.push({{x,y-1},d+1});
        }
    }
    if(a[h][w]>0)cout << ans << endl;
    else cout << -1 << endl;
    return 0;
}

