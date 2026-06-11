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
    int A, B, T;
    cin >> A >> B >> T;

    int lastT = T;
    int ans = 0;
    for (int i = 1; i < 100; i++) {
        lastT -= A;
        if (lastT < 0) {
            ans = (i - 1) * B;
            break;
        }
    }

    cout << ans << endl;

    return 0;
}
