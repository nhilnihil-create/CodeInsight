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
#include <functional>
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
 
const int MAX_N = 18;
int N;
std::string S;

std::map<std::pair<std::string, std::string>, long long> mp;

int main(int argc, char **argv) {
    std::cin >> N;
    std::cin >> S;

    for (int i = 0; i < (1 << N); i++) {
        std::bitset<MAX_N> bs(i);
        std::string backR, backB;
        for (int j = 0; j < N; j++) {
            if (bs.test(j)) {
                backR.push_back(S[N+j]);
            } else {
                backB.push_back(S[N+j]);
            }
        }
        mp[std::pair<std::string, std::string>({backR, backB})]++;
    }

    long long ret = 0;

    for (int i = 0; i < (1 << N); i++) {
        std::bitset<MAX_N> bs(i);
        std::string frontR, frontB;
        for (int j = 0; j < N; j++) {
            if (bs.test(j)) {
                frontR.push_back(S[j]);
            } else {
                frontB.push_back(S[j]);
            }
        }
        std::reverse(frontR.begin(), frontR.end());
        std::reverse(frontB.begin(), frontB.end());

        ret += mp[std::pair<std::string, std::string>({frontB, frontR})];
        ret = ret;
    }

    std::cout << ret << std::endl;
    
    return 0;
}