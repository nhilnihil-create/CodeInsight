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

const int MAX_N = 200050;
int N;
long long x[MAX_N], XG;

long long coeff[MAX_N];

long long energy(const int num) {
    long long ret = 0;
    for (int i = 0; i < N; i++) {
        ret += x[N-i] * coeff[i/num];
    }
    ret += XG * num;
    ret += XG * N;
    return ret;
}

int main(int argc, char **argv) {
    std::cin >> N >> XG;

    for (int i = 1; i <= N; i++) {
        std::cin >> x[i];
    }

    coeff[0] = 5;
    for (int i = 1; i <= N; i++) {
        coeff[i] = i * 2 + 3;
    }

    long long ret = energy(1);
    if (N <= 2000) {
        for (int i = 2; i <= N; i++) {
            //std::cout << i << " " << energy(i) << std::endl;
            ret = std::min(ret, energy(i));
        }
    } else {
        if (energy(1) < energy(2) && energy(N-1) < energy(N)) {
            ret = energy(1);
        } else if (energy(1) > energy(2) && energy(N-1) > energy(N)) {
            ret = energy(N);
        } else {
            int lb = 1;
            int ub = N;
            while (lb + 2 < ub) {
                int mid = (lb + ub) / 2;

                long long v1 = energy(mid - 1);
                long long v2 = energy(mid);
                long long v3 = energy(mid + 1);

                ret = v2;

                if (v1 == v3) {
                    //ret = v2;
                    lb = mid - 1;
                    ub = mid + 1;
                    break;
                } else if (v1 < v2 && v2 < v3) {
                    ub = mid;
                } else if (v1 > v2 && v2 > v3) {
                    lb = mid;
                } else {
                    lb = mid - 1;
                    ub = mid + 1;
                    //ret = v2;
                    break; // 本当か？
                }
            }
            for (int i = std::max(1, lb - 5); i <= std::min(ub + 5, N); i++) {
                ret = std::min(ret, energy(i));
            }
        }
    }

    std::cout << ret << std::endl;
    
    return 0;
}