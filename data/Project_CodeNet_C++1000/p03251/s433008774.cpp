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
using namespace std;
int main() {
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    bool r = true;
    vector<int> x(n);
    vector<int> y(m);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> y[i];
    }
    if (a >= b) {
        r = false;
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++) {
            if (x[i] >= y[j]) {
                r = false;
            }
            if (a >= y[j] || b <= x[i]) {
                r = false;
            }
        }
    }
    if (r) {
        cout << "No War" << endl;
    }
    else {
        cout << "War" << endl;
    }
}