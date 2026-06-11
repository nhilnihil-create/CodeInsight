#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
using P = pair<int, int>;

#define roop(i, n) for(int i = 0;i < n;i++)
#define INF -1

int h, w;
vector<string> field;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int main(void){

    cin >> h >> w;
    roop(i, h){
        string s; cin >> s;
        field.push_back(s);
    }

    queue<P> que;
    vector<vector<int>> value(h, vector<int>(w, INF));

    roop(i, h){
        roop(j, w){
            if(field[i][j] == '#'){
                value[i][j] = 0;
                que.push(P(i, j));
            }
        }
    }


    while(!que.empty()){
        P p = que.front();
        que.pop();

        int y = p.first;
        int x = p.second;

        for(int i = 0;i < 4;i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(nx < 0 || w <= nx || ny < 0 || h <= ny) continue;
            if(value[ny][nx] != INF) continue;

            que.push(P(ny, nx));
            value[ny][nx] = value[y][x] + 1;
        }
    }

    int ans = 0;
    roop(i, h){
        roop(j, w){
            ans = max(ans, value[i][j]);
        }
    }

    cout << ans << endl;

    return 0;
}