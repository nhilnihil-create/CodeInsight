#include<bits/stdc++.h>
using namespace std;

int H, W;
vector<string> A;
vector<vector<int>> seen;
queue<pair<int, int>> to_visit;
vector<int> dx = {1, 0, -1, 0}, dy = {0, 1, 0, -1};

int main() {
    cin >> H >> W;
    A.resize(H);
    seen.assign(H, vector<int>(W, -1));
    for (int i = 0; i < H; i++) {
        cin >> A.at(i);
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if(A.at(i).at(j) == '#') {
                pair<int, int> p = make_pair(i, j);
                to_visit.push(p);
                seen.at(i).at(j) = 0;
            }
        }
    }

    while(to_visit.size() > 0) {
        pair<int, int> p = to_visit.front();
        to_visit.pop();
        int x = p.first, y = p.second;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx.at(i), ny = y + dy.at(i);
            if(nx >= 0 && nx < H && ny >= 0 && ny < W && seen.at(nx).at(ny) == -1) {
                seen.at(nx).at(ny) = seen.at(x).at(y) + 1;
                to_visit.push(make_pair(nx, ny));
            }
        }
    }

    int ans = -1;
    for (int i = 0; i < H; i++) {
        int max_row = *max_element(seen.at(i).begin(), seen.at(i).end());
        ans = max(ans, max_row);
    }

    cout << ans << endl;
}