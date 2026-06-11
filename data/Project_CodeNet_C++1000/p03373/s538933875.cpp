#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <bitset>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <string>
#include <chrono>
#include <random>
#include <cmath>
#include <cassert>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <functional>
#include <sstream>

using namespace std;


int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int A, B, C;
    int X, Y;
    cin >> A >> B >> C >> X >> Y;

    long long res = 1LL << 60;
    for (int i = 0; i <= 2 * X || i <= 2 * Y; i += 2) {
        long long ans = i * 1LL * C;
        ans += max(0, X - i / 2) * 1LL * A;
        ans += max(0, Y - i / 2) * 1LL * B;
        res = min(res, ans);
    }

    cout << res << '\n';


    return 0;
}