#include <stdio.h>
#include <assert.h>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
#include <queue>
#include <set>
#include <cmath>
#include <unordered_map>
#include <functional>
//#include <unordered_set>
//#include <boost/container/static_vector.hpp>
//#include <boost/unordered_set.hpp>
//#include <boost/unordered_map.hpp>
//#include <unistd.h>

//#include <cv.h>
//#include <highgui.h>
#include <stdlib.h>
#include <time.h>

#include <string>

const int MAX_N = 100050;
int N;
long long L[MAX_N], R[MAX_N];

long long solve() {

    std::vector<int> lp, rp;
    for (int i = 1; i <= N; i++) {
        lp.push_back(i);
        rp.push_back(i);
    }
    std::sort(lp.begin(), lp.end(),
        [](const int a, const int b) { return L[a] > L[b]; }
    );
    std::sort(rp.begin(), rp.end(),
        [](const int a, const int b) { return R[a] < R[b]; }
    );

    long long ret = 0;
    long long cur = 0;
    int lv = 0;
    int rv = 0;

    while (true) {
        if (lv == rv) {
            if (cur < L[lp[lv]]) {
                ret += L[lp[lv]] - cur;
                cur = L[lp[lv]];
                lv++;
            } else {
                ret += labs(cur);
                break;
            }
        } else {
            if (R[rp[rv]] < cur) {
                ret += cur - R[rp[rv]];
                cur = R[rp[rv]];
                rv++;
            } else {
                ret += labs(cur);
                break;
            }
        }
    }

    return ret;
}

int main(int argc, char **argv) {
    std::cin >> N;

    for (int i = 1; i <= N; i++) {
        std::cin >> L[i] >> R[i];
    }

    long long ret = solve();

    std::swap(L, R);
    for (int i = 1; i <= N; i++) {
        L[i] = -L[i];
        R[i] = -R[i];
    }

    ret = std::max(ret, solve());

    std::cout << ret << std::endl;
    
    return 0;
}