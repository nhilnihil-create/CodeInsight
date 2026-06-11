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

//#include <cv.h>
//#include <highgui.h>
#include <stdlib.h>
#include <time.h>

#include <string>

const int MAX_N = 3000;
int N, K, Q, A[MAX_N];

std::vector<int> seg[MAX_N];

int main(int argc, char **argv) {
    std::cin >> N >> K >> Q;

    for (int i = 1; i <= N; i++) {
        std::cin >> A[i];
    }

    int ret = 1000000000;
    for (int i = 1; i <= N; i++) {
        int seg_idx = 0;

        for (int j = 0; j <= N; j++) {
            seg[j].clear();
        }

        for (int j = 1; j <= N; j++) {
            if (A[i] <= A[j]) {
                seg[seg_idx].push_back(A[j]);
            } else if (0 < seg[seg_idx].size()) {
                seg_idx++;
            }
        }

        std::vector<int> cand;

        for (int s = 0; s <= seg_idx; s++) {
            if (K <= seg[s].size()) {
                std::sort(seg[s].begin(), seg[s].end());
                for (int m = 0; m <= seg[s].size() - K; m++) {
                    cand.push_back(seg[s][m]);
                }
            }
        }

        //std::cout << i << " " << cand.size() << std::endl;

        if (Q <= cand.size()) {
            std::sort(cand.begin(), cand.end());
            ret = std::min(ret, cand[Q-1] - A[i]);
        }
    }

    std::cout << ret << std::endl;
    
    return 0;
}