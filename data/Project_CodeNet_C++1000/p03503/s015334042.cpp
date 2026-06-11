#include <bits/stdc++.h>

using namespace std;

int main (void) {
    int N;
    cin >> N;

    /* 各店の営業時間情報をbit列で表す */
    vector<int> shop(N, 0);
    for ( int i = 0; i < N; i++ ) {
        for ( int jk = 0; jk < 10; jk++ ) {
            int is_open;
            cin >> is_open;
            if ( is_open ) shop.at(i) |= 1 << jk;
        }
    }

    vector<vector<int>> P(N, vector<int>(11));
    for ( int i = 0; i < N; i++ ) {
        for ( int j = 0; j <= 10; j++ ) {
            cin >> P.at(i).at(j);
        }
    }

    /* 店のありうる開け方を全部試す */
    long long ans = LLONG_MIN;
    for ( int open = 1; open < (1 << 10); open++ ) {
        long long temp = 0;
        for ( int i = 0; i < N; i++ ) {
            bitset<10> both(open & shop.at(i));
            temp += P.at(i).at(both.count());
        }
        ans = max(ans, temp);
    }

    cout << ans << endl;
    return 0;
}
