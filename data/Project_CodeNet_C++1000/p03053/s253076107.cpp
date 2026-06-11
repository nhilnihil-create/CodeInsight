#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e3 + 5;
int vis[MAX][MAX], grid[MAX][MAX], m, n;
char c;
bool inside(int x, int y, int a, int b){
    return 0 <= x + a && x + a < n && 0 <= y + b && y + b < m;
}
int main(){
    cin >> n >> m;
    queue<pair<pair<int, int>, int>> queue;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> c;
            if (c == '#'){
                queue.emplace(make_pair(make_pair(i, j), 0));
                vis[i][j] = 1;
            }
        }
    }
    int ans = 0;
    while(queue.size()){
        pair<pair<int, int>, int> p = queue.front();
        int cx = p.first.first;
        int cy = p.first.second;
        int ct = p.second;
        ans = max(ans, ct);
        queue.pop();
        for (int a: {-1, 0, 1}){
            for (int b: {-1, 0, 1}){
                if (abs(a) != abs(b) && inside(cx, cy, a, b)){
                    if (!vis[cx + a][cy + b]){
                        queue.emplace(make_pair(make_pair(cx + a, cy + b), ct + 1));
                        vis[cx + a][cy + b] = 1;
                    }
                }
            }
        }
    }
    cout << ans << "\n";
}