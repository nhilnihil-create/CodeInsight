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
    int N, K;
    cin >> N >> K;
    int A = 1;

    for (int i = 0; i < N; i++) {
        if (min(A * 2, A + K) == A * 2) {
            A = A * 2;
        }
        else {
            A = A + K;
        }
    }
    cout << A << endl;
}