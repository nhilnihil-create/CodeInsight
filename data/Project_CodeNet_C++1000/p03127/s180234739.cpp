#include <bits/stdc++.h>
#include <iostream>
#include<math.h>
using namespace std;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
int main()
{
    int64_t N;
    cin >> N;
    vector<int64_t>vec(N);
    for (int64_t i=0; i<N; i++) {
        cin >> vec.at(i);
    }

    sort(vec.begin(), vec.end());
    int64_t min_ = INT64_MAX;
    int64_t min_index = 0;
    for (int i=1; i<N; i++) {
        vec[i] = vec[i] % vec[0];
        if (vec[i] > 0 && min_ > vec[i]) {
            min_ = vec[i];
            min_index = i;
        }
    }

    bool ikeru = true;
    while (ikeru) {
        ikeru = false;
        int64_t new_min = INT64_MAX;
        int64_t new_min_index = INT64_MAX;
        for (int64_t i=0; i<N; i++) {
            if (i != min_index) {
                vec[i] = vec[i] % min_;
                if (vec[i] != 0 && new_min > vec[i]) {
                    new_min = vec[i];
                    new_min_index = i;
                }
            }
        }

        if (min_ > new_min) {
            ikeru = true;
            min_ = new_min;
            min_index = new_min_index;
        }
    }

    int64_t ans = INT64_MAX;
    for (int64_t i=0; i<N; i++) {
        if (vec[i] > 0) {
            ans = min(ans, vec[i]);
        }
    }

    cout << ans << endl;
    return 0;
}