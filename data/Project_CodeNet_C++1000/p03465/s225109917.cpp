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
#include <bitset>
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

const int MAX_N = 2010;
const int MAX_V = 2000;

int N, A[MAX_N];

std::bitset<MAX_V * MAX_N> dp;

int main(int argc, char **argv) {
    std::cin >> N;

    for (int i = 1; i <= N; i++) {
        std::cin >> A[i];
    }

    int sum = 0;
    for (int i = 1; i <= N; i++) {
        sum += A[i];
    }

    dp.set(0);

    for (int i = 1; i <= N; i++) {
        dp = (dp | (dp << A[i]));
    }

    int begin = (sum % 2 == 0) ? sum / 2 : sum / 2 + 1;

    for (int i = begin; i <= sum; i++) {
        if (dp[i]) {
            std::cout << i << std::endl;
            return 0;
        }
    }
    return 0;
}