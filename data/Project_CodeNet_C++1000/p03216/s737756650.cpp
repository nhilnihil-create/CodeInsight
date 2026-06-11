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
#include <bitset>
//#include <unordered_map>
//#include <unordered_set>
//#include <boost/container/static_vector.hpp>
//#include <boost/unordered_set.hpp>
//#include <boost/unordered_map.hpp>
//#include <unistd.h>

const int MAX_N = 1000050;
std::string S;
const int MAX_Q = 100;
int N, Q, k_in[MAX_Q];

long long solve(int k) {
    long long ret = 0;
    long long eff_D = 0;
    long long eff_M = 0;
    long long eff_DM = 0;
    
    for (int i = 0; i < N; i++) {
        if (S[i] == 'D') {
            eff_D++;
        } else if (S[i] == 'M') {
            eff_M++;
            eff_DM += eff_D;
        } else if (S[i] == 'C') {
            ret += eff_DM;
        }

        if (0 <= i - k + 1) {
            if (S[i-k+1] == 'D') {
                eff_D--;
                eff_DM -= eff_M;
            } else if (S[i-k+1] == 'M') {
                eff_M--;
            }
        }

        if (0 <= i - k) {
            if (S[i-k] == 'D') {
                //eff_DM -= eff_M;
            } else if (S[i-k] == 'M') {
                //eff_M--;
            }
        }
        //std::cout << "check:" << i << " " << eff_D << " " << eff_M << " " << eff_DM << " " << ret << std::endl;
    }

    return ret;
}

int main(int argc, char **argv) {
    std::cin >> N;
    std::cin >> S;
    std::cin >> Q;

    for (int i = 0; i < Q; i++) {
        std::cin >> k_in[i];
    }

    for (int i = 0; i < Q; i++) {
        std::cout << solve(k_in[i]) << std::endl;
    }

    return 0;
}