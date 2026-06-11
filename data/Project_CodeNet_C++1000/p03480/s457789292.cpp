#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <bitset>
#include <array>
#include <vector>
#include <queue>
#include <set>
#include <cmath> // 変数名にy1が使えなくなるかも…。
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <limits>
#include <functional>
#include <string>

typedef __int128_t int128_t;
std::istream &operator>>(std::istream& input, int128_t& value) { // int128_tの入力。入力が64bitに収まる前提。
    int64_t tmp; input >> tmp; value = tmp;
    return input;
}
std::ostream &operator<<(std::ostream& output, const int128_t value) { // int128_tの出力。出力が64bitに収まる前提。
    output << (int64_t)value;
    return output;
}

int64_t imax(const int64_t a, const int64_t b) { return std::max(a, b); } // std::max, std::min は型が違うとエラーになるため、ラッパーを作る。
int64_t imin(const int64_t a, const int64_t b) { return std::min(a, b); }

#define rep(i, begin, end) for(int64_t i = ((int64_t)begin); i <= ((int64_t)end); i++)
#define rev(i, begin, end) for(int64_t i = ((int64_t)begin); ((int64_t)end) <= i; i--)

#define input1(begin, end, v1) v1.resize((end)+1); for (int i = (begin); i <= (end); i++) { std::cin >> v1[i]; }
#define input2(begin, end, v1, v2) v1.resize((end)+1); v2.resize((end)+1); for (int i = (begin); i <= (end); i++) { std::cin >> v1[i] >> v2[i]; } 
#define input3(begin, end, v1, v2, v3) v1.resize((end)+1); v2.resize((end)+1); v3.resize((end)+1); for (int i = (begin); i <= (end); i++) { std::cin >> v1[i] >> v2[i] >> v3[i]; } 

std::vector<int> irange(const int begin, const int end) {
    std::vector<int> ret; for (int i = begin; i <= end; i++) { ret.push_back(i); }
    return ret;
}

template <typename T>
void printvec(const std::vector<T>& vec) {
    for (int i = 0; i < vec.size(); i++) { std::cout << vec[i] << " "; } std::cout << std::endl;
}

//int ;
//int128_t X, Y;
//std::vector<int> ;
//std::vector<int128_t> ;
std::string S;
//std::vector<std::string> ;
//double ;
//std::vector<double> ;

int main(int argc, char **argv) {
    std::cin >> S;
    
    int ret = S.size();
    rep (i, 0, S.size() - 2) {
        if (S[i+1] != S[i]) {
            ret = imin(ret, imax(i+1, S.size() - (i+1)));
        }
    }

    std::cout << ret << std::endl;
    
    return 0;
}