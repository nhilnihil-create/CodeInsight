#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

#include <limits.h>

using namespace std;

typedef long long ll;

template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

vector<int> ts;
vector<int> xs;
vector<int> ys;

bool solve(const int N) {
    for (int i = 1; i <= N; i++) {
        int diff_t = ts[i] - ts[i - 1];
        int diff_x = abs(xs[i] - xs[i - 1]);
        int diff_y = abs(ys[i] - ys[i - 1]);
        // printf("diff_t: %d, diff_x: %d, diff_y: %d\n", diff_t, diff_x, diff_y);

        if (diff_t < diff_x + diff_y) {
            return false;
        }
        if (abs(diff_x + diff_y - diff_t) % 2 != 0) {
            return false;
        }
    }

    return true;
}

int main(void) {
    int N;
    cin >> N;

    ts.resize(N + 1);
    xs.resize(N + 1);
    ys.resize(N + 1);
    ts[0] = 0;
    xs[0] = 0;
    ys[0] = 0;
    for (int i = 1; i <= N; i++) {
        int t, x, y;
        cin >> t >> x >> y;
        ts[i] = t;
        xs[i] = x;
        ys[i] = y;
    }

    if (solve(N)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
