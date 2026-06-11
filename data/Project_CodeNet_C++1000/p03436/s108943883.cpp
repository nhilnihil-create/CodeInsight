#include <bits/stdc++.h>
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)
#define ALL(x) (x).begin(),(x).end() 
#define SIZE(x) ((ll)(x).size())
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
#define INF 1000000000
using namespace std;
typedef long long ll;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<char>> s(H, vector<char>(W));
    REP(i, H){
        REP(j, W){
            cin >> s[i][j];
        }
    }

    vector<vector<int>> dist(H, vector<int>(W, -1));
    queue<pair<int,int>> que;

    dist[0][0] = 0;
    que.push(make_pair(0, 0));

    //BFS実行部分//
    while(!que.empty()){
        pair<int, int> current_pos = que.front();   //キューの先頭の確認
        int x = current_pos.first;
        int y = current_pos.second;
        que.pop();

        REP(dir, 4){
            int next_x = x + dx[dir];
            int next_y = y + dy[dir];

            if(next_x < 0 || next_x >= H || next_y < 0 || next_y >= W){
                continue;
            }
            if(s[next_x][next_y] == '#') continue;

            if(dist[next_x][next_y] == -1){
                que.push(make_pair(next_x, next_y));
                dist[next_x][next_y] = dist[x][y] + 1;
            }
        }
    }

    int coun = 0, ans = 0;
    if(dist[H-1][W-1] == -1){
        cout << -1 << endl;
    }
    else{
        REP(i, H){
            REP(j, W){
                if(s[i][j] == '.') coun++;
            }
        }
        ans = coun -1 - dist[H-1][W-1];
        cout << ans << endl;
    }
}