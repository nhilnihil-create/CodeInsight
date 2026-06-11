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
    long long tmp; input >> tmp; value = tmp;
    return input;
}
std::ostream &operator<<(std::ostream& output, const int128_t value) { // int128_tの出力。出力が64bitに収まる前提。
    output << (long long)value;
    return output;
}

// binary search result
struct BSR {
    bool found; // 条件を満たす範囲が見つかったか。falseの場合、begin,endは意味を持たない。
    int128_t begin; // [begin, end]で条件が成り立つ。
    int128_t end;
    BSR(bool found_in, int128_t begin_in, int128_t end_in) { found = found_in; begin = begin_in; end = end_in; }
    //BSR(bool found_in, int128_t begin_in, int128_t end_in) : found(found_in), begin(begin_in), end(end_in) {}
};

//template<class Fn> BSR binary_search(int128_t L, int128_t R, Fn func) {
BSR binary_search(int128_t L, int128_t R, std::function<bool(int128_t)> func) {
    const bool res_L = func(L);
    const bool res_R = func(R);
    if (res_L && res_R) {
        return BSR(true, L, R);
    } else if (!res_L && !res_R) {
        return BSR(false, 0, 0);
    } else {
        int128_t lb = L;
        int128_t ub = R;
        while (lb + 1 < ub) {
            int128_t mid = (lb + ub) / 2;
            if (res_L == func(mid)) {
                lb = mid;
            } else {
                ub = mid;
            }
        }
        return res_L ? BSR(true, L, lb) : BSR(true, ub, R);
    }
}

const int MAX_N = 200050;

int N, Q;
std::string S;

char tile[MAX_N];
char t[MAX_N], d[MAX_N];

int cal_pos(int pos) {
    for (int i = 1; i <= Q; i++) {
        if (t[i] == tile[pos]) {
            if (d[i] == 'L') {
                pos--;
            } else {
                pos++;
            }
        }
        if (pos == 0 || pos == N + 1) {
            break;
        }
    }
    return pos;
}

int main(int argc, char **argv) {
    std::cin >> N >> Q;
    std::cin >> S;

    for (int i = 1; i <= Q; i++) {
        std::cin >> t[i] >> d[i];
    }

    for (int i = 0; i < S.size(); i++) {
        tile[i+1] = S[i];
    }

    int ret = N;
    BSR bsr = binary_search(1, N, [](int j){
        return cal_pos(j) == 0;
    });
    if (bsr.found) {
        ret -= bsr.end - bsr.begin + 1;
    }
    bsr = binary_search(1, N, [](int j){
        return cal_pos(j) == N + 1;
    });
    if (bsr.found) {
        ret -= bsr.end - bsr.begin + 1;
    }

    std::cout << ret << std::endl;

    return 0;
}

