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

const int MAX_N = 18;
int N;
int A[1 << MAX_N];
std::vector<int> bits_num[MAX_N];

std::vector<int> choose_idx[1 << MAX_N];

bool has_bit(int x, int loc) {
    return (x >> loc) & 1;
}

int bit_count(int x) {
    int ret = 0;
    for (int i = 0; i < MAX_N; i++) {
        if (has_bit(x, i)) {
            ret++;
        }
    }
    return ret;
}
 
int main(int argc, char **argv) {
    std::cin >> N;

    int pow_max = (1 << N);

    for (int i = 0; i < pow_max; i++) {
        std::cin >> A[i];
    }

    for (int i = 0; i < pow_max; i++) {
        bits_num[bit_count(i)].push_back(i);
    }

    for (int i = 1; i < pow_max; i++) {
        choose_idx[i].push_back(0);
        choose_idx[i].push_back(i);
        std::sort(choose_idx[i].begin(), choose_idx[i].end(),
            [](const int& a, const int& b) { return A[a] > A[b]; }
        );
    }

    for (int bn = 1; bn < N; bn++) {
        for (int orig : bits_num[bn]) {
            for (int add : bits_num[1]) {
                int next = orig | add;
                choose_idx[next].push_back(choose_idx[orig][0]);
                choose_idx[next].push_back(choose_idx[orig][1]);

                std::sort(choose_idx[next].begin(), choose_idx[next].end(),
                    [](const int& a, const int& b) { return A[a] > A[b]; }
                );
                std::unique(choose_idx[next].begin(), choose_idx[next].end());
                choose_idx[next].resize(2);
            }
        }
    }

    int ret = 0;
    for (int i = 1; i < pow_max; i++) {
        ret = std::max(ret, A[choose_idx[i][0]] + A[choose_idx[i][1]]);
        std::cout << ret << std::endl;
    }

    return 0;
}