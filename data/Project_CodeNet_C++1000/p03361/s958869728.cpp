#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> P;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

int main(){
    int H, W;
    cin >> H >> W;
    vector<vector<char>> s(H, vector<char>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> s.at(i).at(j);
        }
    }
    vector<vector<int>> c(H, vector<int>(W, 0));
    for (int x = 0; x < H; x++) {
        for (int y = 0; y < W; y++) {
            if (s.at(x).at(y) == '#') c.at(x).at(y)++;
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx >= 0 && nx < H && ny >= 0 && ny < W && s.at(nx).at(ny) == '#') {
                    c.at(x).at(y)++;
                }
            }
        }
    }
    for (int x = 0; x < H; x++) {
        for (int y = 0; y < W; y++) {
            if (s.at(x).at(y) == '#' && c.at(x).at(y) < 2) {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}
