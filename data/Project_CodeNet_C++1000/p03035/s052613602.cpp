#include <algorithm>
#include <cassert>
#include <climits>
#include <cstdio>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

const int INF = 1e9;
const long long LINF = 1e18;

int main() {
    int A, B;
    cin >> A >> B;

    if (A >= 13) {
        cout << B << endl;
    } else if (A >= 6) {
        cout << B / 2 << endl;
    } else {
        cout << 0 << endl;
    }

    return 0;
}