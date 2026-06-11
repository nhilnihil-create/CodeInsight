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

const int MAX_N = 2e5 + 10;
const int MOD = 1e9 + 7;
int N;
int c[MAX_N];

int128_t prev[MAX_N] = {};


int main(int argc, char **argv) {
    std::cin >> N;
    for (int i = 1; i <= N; i++) {
        std::cin >> c[i];
    }

    int128_t ret = 1;
    for (int i = 1; i <= N; i++) {
        if (c[i] != c[i-1]) {
            ret = (ret + prev[c[i]]) % MOD;
        }
        prev[c[i]] = ret;
    }
    
    std::cout << ret << std::endl;
    return 0;
}

