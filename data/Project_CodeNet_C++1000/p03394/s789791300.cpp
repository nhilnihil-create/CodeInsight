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
#include <iomanip>
#include <string>



//const int MAX_N = 55;
int N;

int main(int argc, char **argv) {
    std::cin >> N;

    std::vector<int> ret;

    if (N == 3) {
        ret.push_back(2); ret.push_back(5); ret.push_back(63); 
    } else if (N == 4) {
        ret.push_back(2); ret.push_back(5); ret.push_back(20); ret.push_back(63); 
    } else {
        // N >= 5;
        int current_sum = 0;
        int group_num = N / 4;
        int rest = N % 4;

        for (int i = 0; i < group_num; i++) {
            ret.push_back(6*i + 2);
            ret.push_back(6*i + 3);
            ret.push_back(6*i + 4);
            ret.push_back(6*i + 6);
        }

        if (rest == 3) {
            if (group_num % 2 == 0) {
                ret.push_back(6*group_num + 2);
                ret.push_back(6*group_num + 4);
                ret.push_back(6*group_num + 6);
            } else {
                ret.push_back(6*group_num + 2);
                ret.push_back(6*group_num + 3);
                ret.push_back(6*group_num + 4);
            }
        } else if (rest == 2) {
            if (group_num % 2 == 0) {
                ret.push_back(6*group_num + 2);
                ret.push_back(6*group_num + 4);
            } else {
                ret.push_back(6*group_num + 3);
                ret.push_back(6*group_num + 6);
            }
        } else if (rest == 1) {
            if (group_num % 2 == 0) {
                ret.push_back(6*group_num + 6);
            } else {
                ret.push_back(6*group_num + 3);
            }
        } else {
            if (group_num % 2 != 0) {
                ret.resize(4*(group_num - 1));
                ret.push_back(6*(group_num - 1) + 2);
                ret.push_back(6*(group_num - 1) + 4);
                ret.push_back(6*(group_num - 1) + 6);
                ret.push_back(6*(group_num - 1) + 12);
            }
        }
    }

    for (int i = 0; i < ret.size(); i++) {
        std::cout << ret[i] << " ";
    }

    std::cout << std::endl;

    return 0;
}