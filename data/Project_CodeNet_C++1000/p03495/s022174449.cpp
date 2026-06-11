#include <bits/stdc++.h>

using namespace std;

int main (void) {
    int N, K;
    cin >> N >> K;
    map<int, int> ball;
    int a;
    for ( int i=0; i<N; i++ ) {
        cin >> a;
        ball[a]++;
    }

    /* 各ボールの値の数をソートできるように
     * vector に入れ替える */
    vector<int> n_num;
    for ( auto itr : ball ) {
        n_num.push_back(itr.second);
    }

    sort(n_num.begin(), n_num.end());

    /* ボールの数が少ない方から書き換えていく */
    int idx = 0;
    int ans = 0;
    int kinds = ball.size() - K;
    while ( kinds > 0 ) {
        ans += n_num.at(idx);
        idx++;
        kinds--;
    }

    cout << ans << endl;

    return 0;
}
