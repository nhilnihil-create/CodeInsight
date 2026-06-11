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

int128_t imax(const int128_t a, const int128_t b) { return std::max(a, b); } // std::max, std::min は型が違うとエラーになるため、ラッパーを作る。
int128_t imin(const int128_t a, const int128_t b) { return std::min(a, b); }

#define rep(i, begin, end) for(int64_t i = ((int64_t)begin); i <= ((int64_t)end); i++) // (int64_t)end としておくと、end = v.size() - 2 みたいな入力で、v.size()が1でも正常(end = -1になる）に挙動する。
#define rev(i, begin, end) for(int64_t i = ((int64_t)begin); ((int64_t)end) <= i; i--)

#define input1(begin, end, v1) v1.resize((end)+1); for (int i = (begin); i <= (end); i++) { std::cin >> v1[i]; }
#define input2(begin, end, v1, v2) v1.resize((end)+1); v2.resize((end)+1); for (int i = (begin); i <= (end); i++) { std::cin >> v1[i] >> v2[i]; } 
#define input3(begin, end, v1, v2, v3) v1.resize((end)+1); v2.resize((end)+1); v3.resize((end)+1); for (int i = (begin); i <= (end); i++) { std::cin >> v1[i] >> v2[i] >> v3[i]; }
#define input4(begin, end, v1, v2, v3, v4) v1.resize((end)+1); v2.resize((end)+1); v3.resize((end)+1); v4.resize((end)+1); for (int i = (begin); i <= (end); i++) { std::cin >> v1[i] >> v2[i] >> v3[i] >> v4[i]; }

std::vector<int> irange(const int begin, const int end) {
    std::vector<int> ret; for (int i = begin; i <= end; i++) { ret.push_back(i); }
    return ret;
}

template <typename T>
void printvec(const std::vector<T>& vec) {
    for (int i = 0; i < vec.size(); i++) { std::cout << vec[i] << " "; } std::cout << std::endl;
}

int128_t gcd(int128_t a, int128_t b) {
    if (b == 0) { return a; }
    return gcd(b, a % b);
}

int T;
//int128_t ;
std::vector<int128_t> a, b, c, d;
//std::vector<int128_t> A, B;
//std::string ;
//std::vector<std::string> ;
//double ;
//std::vector<double> ;

//const int MAX_N = 5010;

bool solve(int128_t A, int128_t B, int128_t C, int128_t D) {
    if (A < B) { return false; }
    if (D < B) { return false; }
    if (C >= B) { return true; }
    if (C < A % B) { return false; }
    if (D % B == 0) { return true; }

    //std::cout << "check" << std::endl;
    int128_t g = gcd(B, D % B);
    //std::cout << "check2:" << g << std::endl;

    int128_t n = (C - A % B) / g;
    int128_t t = A % B + g * n;
    if (B <= t + g) {
        return true;
    } else {
        return false;
    }
}

int main(int argc, char **argv) {
    std::cin >> T;

    input4(1, T, a, b, c, d);

    rep (i, 1, T) {
        //std::cout << a[i] << " " << b[i] << " " << c[i] << " " << d[i] << std::endl;
        if (solve(a[i], b[i], c[i], d[i])) {
            std::cout << "Yes" << std::endl;
        } else {
            std::cout << "No" << std::endl;
        }
    }

    return 0;
}