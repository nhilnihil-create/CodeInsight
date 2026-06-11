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
#include <iomanip>
//#include <unordered_map>
//#include <unordered_set>
//#include <boost/container/static_vector.hpp>
//#include <boost/unordered_set.hpp>
//#include <boost/unordered_map.hpp>
//#include <unistd.h>

//#include <cv.h>
//#include <highgui.h>
#include <stdlib.h>
#include <string>

const int MAX_N = 100050;
int N, M;
int A[MAX_N], B[MAX_N];

std::vector<int> rG[MAX_N];
int rank[MAX_N];
int par[MAX_N];

int calc_rank(const int n) {
    if (rank[n] != -1) {
        return rank[n];
    }

    int ret = 0;
    for (int p : rG[n]) {
        ret = std::max(ret, 1 + calc_rank(p));
    }
    rank[n] = ret;
    return ret;
}

int main(int argc, char **argv) {
    std::cin >> N >> M;

    for (int i = 1; i <= N - 1 + M; i++) {
        std::cin >> A[i] >> B[i];
    }

    for (int i = 1; i <= N - 1 + M; i++) {
        rG[B[i]].push_back(A[i]);
    }

    for (int i = 1; i <= N; i++) {
        rank[i] = -1;
        par[i] = 0;
    }
    for (int i = 1; i <= N; i++) {
        rank[i] = calc_rank(i);
    }

    for (int i = 1; i <= N; i++) {
        for (int p : rG[i]) {
            if (rank[p] + 1 == rank[i]) {
                par[i] = p;
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        std::cout << par[i] << std::endl;
    }

    return 0;
}
