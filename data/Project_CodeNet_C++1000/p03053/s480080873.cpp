#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

char M[1000][1000];
int d[1000][1000];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
int H, W;
const int INF = 1001001001;
queue<pair<int, int> > Q;
int ans = 0;

void bfs(){
    while(!Q.empty()){
        pair<int, int> p = Q.front(); Q.pop();
        int i = p.first;
        int j = p.second;
        rep(k, 4){
            int yn = i+dy[k];
            int xn = j+dx[k];
            if(yn >= 0 && yn < H && xn >= 0 && xn < W){
                if(M[yn][xn] == '#'){
                    continue;
                } else if(d[yn][xn] == INF){
                    Q.push(make_pair(yn, xn));
                    d[yn][xn] = d[i][j] + 1;
                    ans = max(ans, d[yn][xn]);
                }
            }
        }
    }

    return;
}

int main() {
    cin >> H >> W;
    rep(i, H){
        rep(j, W){
            cin >> M[i][j];
            d[i][j] = INF;
            if(M[i][j] == '#'){
                Q.push(make_pair(i, j));
                d[i][j] = 0;
            }
        }
    }

    bfs();

    cout << ans << endl;

    return 0;
}