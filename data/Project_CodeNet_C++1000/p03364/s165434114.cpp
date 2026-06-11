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

const int MAX_N = 350;
int N;

std::string S[MAX_N];
bool is_good[MAX_N][MAX_N];

bool calc_is_good(int i, int j) {
    for (int k = 0; k < N; k++) {
        if (S[(i + k) % N][j] != S[i][(j + k) % N]) {
            return false;
        }
    }
    return true;
}

int main(int argc, char **argv) {
    std::cin >> N;

    for (int i = 0; i < N; i++) {
        std::cin >> S[i];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            is_good[i][j] = calc_is_good(i, j);
        }
    }

    int ret = 0;
    for (int i = 0; i < N; i++) {
        bool is_all_good = true;
        for (int k = 0; k < N; k++) {
            if (!is_good[k][(i + k) % N]) {
                is_all_good = false;
                break;
            }
        }
        if (is_all_good) {
            ret += N;
        }
    }

    std::cout << ret << std::endl;

    return 0;
}