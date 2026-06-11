#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> movement = { make_pair(0, 1),
                                    make_pair(0, -1),
                                    make_pair(-1, 0),
                                    make_pair(1, 0) };

int main (void) {
    int H, W;
    cin >> H >> W;
    vector<string> s(H);
    for ( int i = 0; i < H; i++ ) {
        cin >> s.at(i);
    }

    int ans_init = H * W;
    vector<vector<int>> dist(H, vector<int>(W, 0));
    for ( int row = 0; row < H; row++ ) {
        for ( int col = 0; col < W; col++ ) {
            if ( s.at(row).at(col) == '#' ) {
                dist.at(row).at(col) = -1;
                ans_init--;
            }
        }
    }

    int ans = ans_init;
    queue<pair<int, int>> next;

    next.push(make_pair(0, 0));

    while ( !next.empty() ) {
        pair<int, int> now = next.front(); next.pop();
        int x = now.first;
        int y = now.second;

        if ( x == W-1 && y == H-1 ) {
            ans = ans - dist.at(y).at(x) - 1;
            break;
        }

        for ( auto m : movement ) {
            int x_ = x + m.first;
            int y_ = y + m.second;
            if ( x_ < 0 || W <= x_ || y_ < 0 || H <= y_ )
                continue;
            if ( dist.at(y_).at(x_) != 0 )
                continue;
            dist.at(y_).at(x_) = dist.at(y).at(x) + 1;
            next.push(make_pair(x_, y_));
        }
    }

    if ( ans == ans_init )
        cout << "-1" << endl;
    else
        cout << ans << endl;
    return 0;
}

