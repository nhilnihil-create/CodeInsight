#include <bits/stdc++.h>

using namespace std;

int main (void) {
    int N, K;
    cin >> N >> K;
    vector<int> x(N);
    for ( int i=0; i<N; i++ ) {
        cin >> x.at(i);
    }

    int ans = INT_MAX;
    int candle_dist, first_move;
    for ( int i=0; i<N-(K-1); i++ ) {
        candle_dist = x.at(i+(K-1)) - x.at(i);
        first_move = min(abs(x.at(i)), abs(x.at(i+(K-1))));
        ans = min(ans, candle_dist + first_move);
    }

    cout << ans << endl;
}
