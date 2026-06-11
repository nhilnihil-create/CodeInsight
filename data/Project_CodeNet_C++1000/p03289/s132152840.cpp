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


    string s;
    cin >> s;
    int n = s.length();
    bool res = false;
    if (s[0] == 'A') {
        int cs = 0;
        int lowers = 0;
        for (int i = 2; i + 1 < n; ++i) {
            if (s[i] == 'C') {
                ++cs;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (islower(s[i])) {
                ++lowers;
            }
        }
        if (cs == 1 && lowers + 2 == n) {
            res = true;
        }
    }

    if (res) {
        cout << "AC\n";
    } else {
        cout << "WA\n";
    }
    return 0;
}