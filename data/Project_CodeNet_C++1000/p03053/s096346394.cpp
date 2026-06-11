#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const ll MAXN = 200000;

ll H, W, ans=0, tmp=0;
queue<pair<ll,ll>> Q;
vector<vector<ll>> color;

void bfs() {
    while(!Q.empty()) {
        pair<ll,ll> p = Q.front();
        Q.pop();
        if(p.first+1<H&&color[p.first+1][p.second]==-1) {
            color[p.first+1][p.second]=color[p.first][p.second]+1;
            Q.push(make_pair(p.first+1,p.second));
            ans = max(ans,color[p.first][p.second]+1);
        }
        if(p.first-1>=0&&color[p.first-1][p.second]==-1) {
            color[p.first-1][p.second]=color[p.first][p.second]+1;
            Q.push(make_pair(p.first-1,p.second));
            ans = max(ans,color[p.first][p.second]+1);
        }
        if(p.second+1<W&&color[p.first][p.second+1]==-1) {
            color[p.first][p.second+1]=color[p.first][p.second]+1;
            Q.push(make_pair(p.first,p.second+1));
            ans = max(ans,color[p.first][p.second]+1);
        }
        if(p.second-1>=0&&color[p.first][p.second-1]==-1) {
            color[p.first][p.second-1]=color[p.first][p.second]+1;
            Q.push(make_pair(p.first,p.second-1));
            ans = max(ans,color[p.first][p.second]+1);
        }
    }
}

signed main(){
    cin >> H >> W;
    color.resize(H);
    for(int i=0;i<H;i++) {
        for(int j=0;j<W;j++) {
            color[i].push_back(-1);
        }
    }
    for(int i=0;i<H;i++) {
        for(int j=0;j<W;j++) {
            char c;
            cin >> c;
            if(c=='#') {
                Q.push(make_pair(i,j));
                color[i][j]=0;
            }
        }
    }
    bfs();
    cout << ans << endl;
    return 0;
}