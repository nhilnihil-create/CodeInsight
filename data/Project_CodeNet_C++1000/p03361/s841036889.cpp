#include "bits/stdc++.h"

using namespace std;
using ll = long long;

int main() {

    int H, W;
    cin >> H >> W;

    string grid = string(W + 2, 'X');
    for (int i = 0; i < H; ++i) {
        string s;
        cin >> s;
        grid += 'X' + s + 'X';
    }
    grid += string(W + 2, 'X');

    vector<int> black;
    for (int i = 0; i < grid.length(); ++i)
        if (grid[i] == '#')
            black.push_back(i);

    int INF = 1000;
    int move[] = {1, -1, W + 2, -(W + 2), INF};
    bool ans = true;

    for (int x : black) {
        for (int dx : move) {
            if (dx == INF) {
                cout << "No" << endl;
                exit(0);
            }
            int y = x + dx;
            if (grid[y] == '#')
                break;
        }
    }

    cout << "Yes" << endl;
}
