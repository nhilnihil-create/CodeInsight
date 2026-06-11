// #include <bits/stdc++.h>
#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;
typedef long long ll;

#define all(x) begin(x), end(x)
#define rep(i,n) for(int i=0; i<n; i++)

const ll INF = 1001001001;

int main() {
    int h, w;
    cin >> h >> w;

    int s[h][w];
    char c;
    int white = 0;
    rep(i, h) {
        rep(j, w) {
            cin >> c;
            if (c == '#') s[i][j] = 0;
            else {
                s[i][j] = 1;
                white++;
            }
        }
    }

    bool used[h][w] = {};
    used[0][0] = 1;

    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));

    vector<vector<int>> dist(h, vector<int>(w, INF));
    dist[0][0] = 0;

    bool flag = 0;

    while (q.size()) {
        int cur_H = q.front().first;
        int cur_W = q.front().second;
        q.pop();

        if (cur_H==h-1 && cur_W==w-1) {
            flag = 1;
            break;
        }

        if ((cur_H != 0) && (!used[cur_H-1][cur_W]) && s[cur_H-1][cur_W]) {
            dist[cur_H-1][cur_W] = dist[cur_H][cur_W] + 1;
            used[cur_H-1][cur_W] = 1;
            q.push(make_pair(cur_H-1, cur_W));      // 左
        }
        if ((cur_H != h-1) && (!used[cur_H+1][cur_W]) && s[cur_H+1][cur_W]) {
            dist[cur_H+1][cur_W] = dist[cur_H][cur_W] + 1;
            used[cur_H+1][cur_W] = 1;
            q.push(make_pair(cur_H+1, cur_W));      // 右
        }
        if ((cur_W != 0) && (!used[cur_H][cur_W-1]) && s[cur_H][cur_W-1]) {
            dist[cur_H][cur_W-1] = dist[cur_H][cur_W] + 1;
            used[cur_H][cur_W-1] = 1;
            q.push(make_pair(cur_H, cur_W-1));      // 上
        }
        if ((cur_W != w-1) && (!used[cur_H][cur_W+1]) && s[cur_H][cur_W+1]) {
            dist[cur_H][cur_W+1] = dist[cur_H][cur_W] + 1;
            used[cur_H][cur_W+1] = 1;
            q.push(make_pair(cur_H, cur_W+1));      // 下
        }
    }

    if (flag) cout << white - (dist[h-1][w-1] + 1) << endl;
    else cout << -1 << endl;

    return 0;
}