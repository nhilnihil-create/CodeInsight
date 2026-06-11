#include <bits/stdc++.h>

using namespace std;

vector<int> init_cand (int n) {
    vector<int> cand;

    int i = 6;
    while ( i <= n ) {
        cand.push_back(i);
        i *= 6;
    }

    i = 9;
    while ( i <= n ) {
        cand.push_back(i);
        i *= 9;
    }

    return cand;
}

int main (void) {
    int N;
    cin >> N;

    vector<int> cand = init_cand(N);

    vector<int> ans(N+1);
    /* 1円ずつ引き出したときの回数で初期化 */
    for ( int i = 0; i <= N; i++ ) ans.at(i) = i;

    for ( auto itr : cand ) {
        for ( int i = 1; i <= N; i++ ) {
            if ( i - itr < 0 ) continue;
            ans.at(i) = min(ans.at(i), ans.at(i-itr) + 1);
        }
    }

    cout << ans.at(N) << endl;
    return 0;
}
