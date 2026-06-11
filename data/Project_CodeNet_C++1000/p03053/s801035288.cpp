#include <bits/stdc++.h>
using namespace std;
typedef tuple<int, int, int> tiii;

int main() {
    int H, W; cin >> H >> W;
    vector<string> A(H);
    for (int i = 0; i < H; i++) cin >> A[i];
    int ans = 0;
    vector<vector<bool>> visited(H, vector<bool>(W, false));
    queue<tiii> q; 
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (A[i][j] == '#') {
                q.push(tiii(i, j, 0)); 
                visited[i][j] = true;
            }
        }
    }
    while (!q.empty()) {
        int h, w, a; tie(h, w, a) = q.front(); q.pop();
        ans = a;
        if (0 <= h-1 && !visited[h-1][w]) {q.push(tiii(h-1, w, a+1)); visited[h-1][ w ] = true;}
        if (h+1 < H && !visited[h+1][w]) {q.push(tiii(h+1, w, a+1)); visited[h+1][w] = true;}
        if (0 <= w-1 && !visited[h][w-1]) {q.push(tiii(h, w-1, a+1)); visited[h][w-1] = true;}
        if (w+1 < W && !visited[h][w+1]) {q.push(tiii(h, w+1, a+1)); visited[h][w+1] = true;}
    }
    cout << ans << endl;
}