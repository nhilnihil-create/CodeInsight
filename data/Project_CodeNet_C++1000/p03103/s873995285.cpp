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
    vector<pair<int64_t, int64_t>>vec(N);
    for (int64_t i=0; i<N; i++) {
        int64_t a, b;
        cin >> a >> b;
        vec[i] = make_pair(a, b);
    }
    sort(vec.begin(), vec.end());
    int64_t sum_count = 0;
    int64_t sum_en = 0;
    for (int64_t i=0; i<N; i++) {
        pair<int64_t, int64_t> p = vec[i];
        int64_t rem = M - sum_count;
        int64_t honsuu = min(rem, p.second);
        sum_en += honsuu * p.first;
        sum_count += honsuu;
        if (sum_count >= M) {
            break;
        }
    }

    cout << sum_en << endl;
    return 0;
}