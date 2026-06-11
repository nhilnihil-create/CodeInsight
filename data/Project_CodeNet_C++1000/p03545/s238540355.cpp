#include <algorithm>
#include <bitset>
#include <climits>
#include <complex>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <queue>
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <thread>
#include <tuple>
#include <type_traits>
#include <vector>

#include <stdio.h>

using ll = long long;
using namespace std;

ll to5(ll a) { return a * a * a * a * a; }

int main() {
    ios::sync_with_stdio(false);
    string s;
    cin >> s;

    vector<int> v(4);
    for (int i = 0; i < 4; i++) {
        v[i] = s[i] - '0';
    }

    for (int i = 0b000; i <= 0b111; i++) {
        int sum = v[0];
        if (i & 0b100)
            sum += v[1];
        else
            sum -= v[1];
        if (i & 0b10)
            sum += v[2];
        else
            sum -= v[2];
        if (i & 0b1)
            sum += v[3];
        else
            sum -= v[3];

        if (sum == 7) {
            char f1 = (i & 0b100) ? '+' : '-';
            char f2 = (i & 0b10) ? '+' : '-';
            char f3 = (i & 0b1) ? '+' : '-';
            printf("%d%c%d%c%d%c%d=7\n", v[0], f1, v[1], f2, v[2], f3, v[3]);
            return 0;
        }
    }

    return 0;
}
