#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;
vector<string> A;
int H, W;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int d[1000][1000];
int INF = 1e9+7;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> H >> W;

    for(int i=0; i<H; i++){
        string tmp;
        cin >> tmp;
        A.push_back(tmp);
    }

    queue<P> que;
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            if(A[i][j] == '#'){
                que.push(P(i,j));
                d[i][j] = 0;
            }else{
                d[i][j] = INF;
            }
        }
    }

    while(!que.empty()){
        P p = que.front(); que.pop();
        for(int i=0; i<4; i++){
            int nx = p.first + dx[i];
            int ny = p.second + dy[i];
            if(0 <= nx && nx < H && 0 <= ny && ny < W && d[nx][ny] > d[p.first][p.second] + 1){
                d[nx][ny] = d[p.first][p.second] + 1;
                que.push(P(nx,ny));
            }
        }
    }

    int ans = 0;
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            ans = max(ans, d[i][j]);
        }
    }
    cout << ans << endl;
    return 0;
}
