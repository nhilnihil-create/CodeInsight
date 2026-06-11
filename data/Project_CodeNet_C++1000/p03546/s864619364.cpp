#include <algorithm>
#include <array>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
#include <cassert>

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
using namespace std;

int c[10][10];

int main() {
    int H, W;
    cin >> H >> W;
    rep(i, 10) {
        rep(j, 10) {
            cin >> c[i][j];
        }
    }
    rep(k, 10) {
        rep(i, 10) {
            rep(j, 10) {
                c[i][j] = min(c[i][j], c[i][k] + c[k][j]);
            }
        }
    }
#if 0
    rep(i, 10) {
        rep(j, 10) {
            printf("%4d ", c[i][j]);
        }
        printf("\n");
    }
#endif
    int tmp;
    uint64_t ret = 0;
    rep(i, H) {
        rep(j, W) {
            cin >> tmp;
            if(tmp == -1 || tmp == 1 )
                continue;
            ret += c[tmp][1];
        }
    }
    cout << ret << endl;

    return 0;
}

