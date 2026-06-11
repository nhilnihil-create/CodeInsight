#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <cmath>
#include <iomanip>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
using namespace std;

int main() {
    int M, K;
    cin >> M >> K;
    if (M == 0) {
        if (K == 0) cout << "0\n0\n";
        else cout << "-1\n";
    } else if (M == 1) {
        if (K == 0) cout << "0\n0\n1\n1\n";
        else cout << "-1\n";
    } else {
        if (K >= (1 << M)) {
            cout << "-1\n";
        } else {
            cout << K << "\n";
            rep(i, 1 << M) {
                if (i != K) cout << i << "\n";
            }
            cout << K << "\n";
            for (int i = (1 << M) - 1; i >= 0; --i) {
                if (i != K) cout << i << "\n";
            }
        }
    }
    return 0;
}
