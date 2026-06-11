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
#include <string>

const int MAX_N = 300050;
long long N, A, B;

long long num[MAX_N];

int main(int argc, char **argv) {
    std::cin >> N >> A >> B;
    
    if (A + B - 1 > N) {
        std::cout << -1 << std::endl;
        return 0;
    } else if (A * B < N) {
        std::cout << -1 << std::endl;
        return 0;
    }

    num[1] = B;
    if (2 <= A) {
        int rest = N - B;
        for (int i = 2; i <= A; i++) {
            num[i] = rest / (A - 1);
        }
        for (int j = 1; j <= rest % (A - 1); j++) {
            num[1 + j]++;
        }
    }
    
    int tmp_base = 0;
    for (int i = 1; i <= A; i++) {
        for (int j = num[i]; 1 <= j; j--) {
            std::cout << tmp_base + j << " ";
        }
        tmp_base += num[i];
    }

    std::cout << std::endl;
    
    return 0;

}