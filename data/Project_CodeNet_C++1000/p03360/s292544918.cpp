#include <algorithm>
#include <bitset>
#include <tuple>
#include <cstdint>
#include <cstdio>
#include <cctype>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <cassert>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <limits>
#include <map>
#include <memory>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#define int long long
using namespace std;
signed main() {
    int A, B, C, K;
    cin >> A >> B >> C >> K;

    int X = max(A, max(B, C));
    int Y = min(A, min(B, C));
    int Z = (A + B + C) - (X + Y);
    for (int i = 0; i < K; i++) {
        X *= 2;
    }
    cout << X + Y + Z << endl;
}