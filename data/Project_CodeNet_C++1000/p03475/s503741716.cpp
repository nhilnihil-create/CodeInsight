#include <bits/stdc++.h>

using namespace std;

int main (void) {
    int N;
    cin >> N;
    vector<int> C(N-1);
    vector<int> S(N-1);
    vector<int> F(N-1);
    for ( int i = 0; i < N-1; i++ ) {
        cin >> C.at(i) >> S.at(i) >> F.at(i);
    }

    for ( int start = 0; start < N-1; start++ ) {
        int time = 0;
        for ( int i = start; i < N-1; i++ ) {
            /* 電車が発射する時刻まで待つ */
            if ( time <= S.at(i) )
                time = S.at(i);
            else
                time = ((time - 1) / F.at(i) + 1) * F.at(i);
            /* 次の駅に移動 */
            time += C.at(i);
        }
        cout << time << endl;
    }

    cout << 0 << endl;
    return 0;
}
