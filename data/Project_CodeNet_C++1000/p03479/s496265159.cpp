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

vector<vector<bool>> v;

int main() {
    ios::sync_with_stdio(false);
    ll x, y;
    cin >> x >> y;

    ll ans = 0;

    while (x <= y) {
        ans++;
        x *= 2;
    }
    cout << ans << endl;

    return 0;
}
