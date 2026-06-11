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
    pair<int64_t, int64_t> p = make_pair(0, 0);
    int64_t now_sec = 0;
    bool can_move = true;
    for (int64_t i=0; i<N; i++) {
        int64_t sec, x, y;
        cin >> sec >> x >> y;
        int64_t use_sec = sec - now_sec;
        int64_t idoukyori = abs(x - p.first) + abs(y - p.second);
        if (idoukyori > use_sec) {
            can_move = false;
            break;
        }

        if (use_sec % 2 == 0) {
            if (idoukyori % 2 != 0) {
                can_move = false;
                break;
            }
        } else {
            if (idoukyori % 2 == 0) {
                can_move = false;
                break;
            }
        }

        p = make_pair(x, y);
        now_sec = sec;
    }

    if (can_move) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}