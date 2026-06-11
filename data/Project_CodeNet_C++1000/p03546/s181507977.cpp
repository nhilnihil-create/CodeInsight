#include <bits/stdc++.h>

using namespace std;

int main (void) {
    int H, W;
    cin >> H >> W;
    vector<vector<int>> c(10, vector<int>(10));
    for ( int i = 0; i <= 9; i++ ) {
        for ( int j = 0; j <= 9; j++ ) {
            cin >> c.at(i).at(j);
        }
    }
    vector<vector<int>> A(H+1, vector<int>(W+1));
    for ( int i = 1; i <= H; i++ ) {
        for ( int j = 1; j <= W; j++ ) {
            cin >> A.at(i).at(j);
        }
    }

    /* Warshall-Floyd Algorithm */
    for ( int relay = 0; relay <= 9; relay++ ) {
        for ( int start = 0; start <= 9; start++ ) {
            for ( int dest = 0; dest <= 9; dest++ ) {
                c.at(start).at(dest) = min(c.at(start).at(dest),
                                           c.at(start).at(relay) + c.at(relay).at(dest));
            }
        }
    }

    long long ans = 0;
    for ( int i = 1; i <= H; i++ ) {
        for ( int j = 1; j <= W; j++ ) {
            if ( A.at(i).at(j) >= 0 ) ans += c.at(A.at(i).at(j)).at(1);
        }
    }

    cout << ans << endl;
    return 0;
}
