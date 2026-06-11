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
//#include <unordered_map>
//#include <unordered_set>
//#include <boost/container/static_vector.hpp>
//#include <boost/unordered_set.hpp>
//#include <boost/unordered_map.hpp>
//#include <unistd.h>

const int MAX_N = 200050;

int N, Q;
std::string S;

char tile[MAX_N];
char t[MAX_N], d[MAX_N];

int cal_pos(int pos) {
    for (int i = 1; i <= Q; i++) {
        if (t[i] == tile[pos]) {
            if (d[i] == 'L') {
                pos--;
            } else {
                pos++;
            }
        }
        if (pos == 0 || pos == N + 1) {
            break;
        }
    }
    return pos;
}

int main(int argc, char **argv) {
    std::cin >> N >> Q;
    std::cin >> S;

    for (int i = 1; i <= Q; i++) {
        std::cin >> t[i] >> d[i];
    }

    for (int i = 0; i < S.size(); i++) {
        tile[i+1] = S[i];
    }

    int lb = 0;
    int ub = N + 1;

    while (lb + 1 < ub) {
        int mid = (lb + ub) / 2;
        if (cal_pos(mid) == 0) {
            lb = mid;
        } else {
            ub = mid;
        }
    }

    int left_cond = lb;

    lb = 0;
    ub = N + 1;

    while (lb + 1 < ub) {
        int mid = (lb + ub) / 2;
        if (cal_pos(mid) == N + 1) {
            ub = mid;
        } else {
            lb = mid;
        }
    }

    int right_cond = ub;

    //std::cout << left_cond << " " << right_cond << std::endl;

    int ret = 0;
    for (int i = 1; i <= N; i++) {
        if (left_cond < i && i < right_cond) {
            ret++;
        }
    }
    std::cout << ret << std::endl;

    return 0;
}
