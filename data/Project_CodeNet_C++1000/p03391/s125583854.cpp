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

const int MAX_N = 200050;
const long long MAX_VAL = (long long)100000000000;
int N;
long long A[MAX_N], B[MAX_N];

int main(int argc, char **argv) {
    std::cin >> N;
    for (int i = 1; i <= N; i++) {
        std::cin >> A[i] >> B[i];
    }


    long long total = 0;
    long long minb = MAX_VAL;
    for (int i = 1; i <= N; i++) {
        total += A[i];
        if (B[i] < A[i]) {
            minb = std::min(minb, B[i]);
        }
    }

    if (minb == MAX_VAL) {
        std::cout << 0 << std::endl;
    } else {
        std::cout << total - minb << std::endl;
    }

    return 0;
}