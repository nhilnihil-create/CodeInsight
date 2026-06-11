#include <bits/stdc++.h>
 
#define REP(i,n) for (int i=0;i<(n);++i)
 
using namespace std;
 
enum Result {
    STAY,
    FALL_RIGHT,
    FALL_LEFT,
};
 
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
 
    int N, Q;
    string s;
    cin >> N >> Q >> s;
    vector<char> t(Q), d(Q);
    REP(i, Q) {
        cin >> t[i] >> d[i];
    }
 
    function<Result(int)> f = [&](int x) {
        REP(i, Q) {
            if (t[i] == s[x]) {
                if (d[i] == 'L') {
                    --x;
                    if (x == -1) {
                        return FALL_LEFT;
                    }
                } else if (d[i] == 'R') {
                    ++x;
                    if (x == N) {
                        return FALL_RIGHT;
                    }
                }
            }
        }
        return STAY;
    };
 
    int result = N;
 
    int low = 0;
    int high = N;
    while (low < high) {
        int step = (high - low) / 2;
        int x = low + step;
        if (f(x) == FALL_RIGHT) {
            high = x;
        } else {
            low = x + 1;
        }
    }
    result -= N - low;
 
    low = 0;
    high = N;
    while (low < high) {
        int step = (high - low) / 2;
        int x = low + step;
        if (f(x) == FALL_LEFT) {
            low = x + 1;
        } else {
            high = x;
        }
    }
    result -= low;
 
    cout << result << endl;
 
    return 0;
}