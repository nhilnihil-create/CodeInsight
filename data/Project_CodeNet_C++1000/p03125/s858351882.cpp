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
const double PI=3.14159265358979323846;

int main() {
    int A, B;
    cin >> A >> B;

    if (B % A == 0) {
        cout << A + B << endl;
    } else {
        cout << B - A << endl;
    }

    return 0;
}
