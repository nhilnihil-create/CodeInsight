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
    cout << fixed << setprecision(12);

    int n;
    cin >> n;

    string s = to_string(n);
    int m = s.length();

    bool ok = false;
    for (int i = 0; i < m; ++i) {
        int cnt = 1;
        while (i + 1 < m && s[i + 1] == s[i]) {
            ++i;
            ++cnt;
        }
        if (cnt >= 3) {
            ok = true;
        }
    }

    if (ok) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }


    return 0;
}