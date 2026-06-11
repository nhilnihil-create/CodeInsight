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
    int N;
    cin >> N;

    double ans = 0;
    for (int i = 0; i < N; i++) {
        double x;
        string u;
        cin >> x >> u;

        if (u == "JPY") {
            ans += x;
        } else {
            ans += 380000.0 * x;
        }
    }

    cout << ans << endl;

    return 0;
}
