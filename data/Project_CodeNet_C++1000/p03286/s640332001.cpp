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

    long long n;
    cin >> n;

    int b = -2;
    int ab = abs(b);

    string res;
    if (n == 0) {
        res = "0";
    }
    while (n != 0) {
        int d = (n % b + ab) % ab;
        res += (char)('0' + d);
        n -= d;
        n /= b;

    }

    reverse(res.begin(), res.end());

    cout << res << '\n';
    return 0;
}