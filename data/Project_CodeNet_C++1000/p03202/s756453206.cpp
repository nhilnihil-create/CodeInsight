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
#include <map>
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
long long A[MAX_N];

bool condition(const int num) {
    if (N == 1) {
        return true;
    }

    if (num == 1) {
        for (int i = 2; i <= N; i++) {
            if (A[i] <= A[i-1]) {
                return false;
            } 
        }
        return true;
    }

    std::map<long long, int> mp;
    for (int i = 2; i <= N; i++) {
        if (A[i-1] < A[i]) {
            continue;
        } else {
            mp.erase(mp.upper_bound(A[i]), mp.end());
            long long j = A[i];
            while (mp.find(j) != mp.end() && mp[j] == num - 1) {
                mp.erase(mp.find(j));
                j--;
            }
            if (j == 0) {
                return false;
            } else {
                if (mp.find(j) == mp.end()) {
                    mp[j] = 1;
                } else {
                    mp[j]++;
                }
            }
        }
    }
    return true;
}

int main(int argc, char **argv) {
    std::cin >> N;

    for (int i = 1; i <= N; i++) {
        std::cin >> A[i];
    }

    if (N == 1 || condition(1)) {
        std::cout << 1 << std::endl;
        return 0;
    }

    int lb = 1;
    int ub = N;

    while (lb + 1 < ub) {
        int mid = (lb + ub) / 2;
        if (condition(mid)) {
            ub = mid;
        } else {
            lb = mid;
        }
    }
    std::cout << ub << std::endl;
    
    return 0;
}