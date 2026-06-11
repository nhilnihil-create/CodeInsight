#include <bits/stdc++.h>
#include <iostream>
#include<math.h>
using namespace std;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
int main()
{
    int64_t N, M;
    cin >> N >> M;
    vector<int64_t>vec(M);
    for (int64_t i=0; i<M; i++) {
        cin >> vec.at(i);
    }

    sort(vec.begin(), vec.end());

    if (N >= M) {
        cout << 0 << endl;
    } else {
        int64_t sum = 0;
        vector<int64_t>abs_;
        int64_t hikaku = vec[0];
        for (int64_t i=1; i<M; i++) {
            int64_t idoukyori = abs(vec[i] - hikaku);
            abs_.emplace_back(idoukyori);
            hikaku = vec[i];
            sum += idoukyori;
        }

        sort(abs_.begin(), abs_.end(), greater<int64_t>());
        int64_t i=0;
        // なるべく長い移動距離をパスするようにコマを置く
        while (N > 1) {
            sum -= abs_[i];
            i++;
            N -= 1;
        }

        cout << sum << endl;
    }
    return 0;
}