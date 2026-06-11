#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
typedef long long ll;
ll mod_pow(ll, ll, ll);
ll mod_fact(ll, ll);
ll mod_inv(ll, ll);
//
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int main(){
    int h, w;
    cin >> h >> w;
    vector<vector<bool>> map(h + 2, vector<bool>(w + 2));
    for(int i = 0; i < h; i++){
        string s;
        cin >> s;
        for(int j = 0; j < w; j++){
            if(s[j] == '.'){
                map[i + 1][j + 1] = true;
            }
        }
    }
    vector<vector<int>> dis(h + 2, vector<int>(w + 2));
    queue<pair<int, int>> que;
    for(int i = 1; i <= h; i++){
        for(int j = 1; j <= w; j++){
            if(!map[i][j]) que.push(make_pair(i, j));
        }
    }
    while(!que.empty()){
        auto p = que.front();
        int x = p.first;
        int y = p.second;
        que.pop();
        for(int i = 0; i < 4; i++){
            int cx = x + dx[i];
            int cy = y + dy[i];
            if(!map[cx][cy] || dis[cx][cy]){
                continue;
            }
            dis[cx][cy] = dis[x][y] + 1;
            que.push(make_pair(cx, cy));
        }
    }
    int mx = 0;
    for(int i = 1; i <= h; i++){
        for(int j = 1; j <= w; j++){
            mx = max(mx, dis[i][j]);
        }
    }
    cout << mx;
}