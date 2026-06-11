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
    string d = "/";
    int n = s.length();
    vector<int> ds;
    for (int i = 0; i < n; ++i) {
        auto j = s.find_first_of(d, i);
        if (j == string::npos) {
            j = n;
        }
        ds.push_back(stoi(s.substr(i, j - i)));
        i = j;
    }
    if (ds[0] <= 2019 && ds[1] <= 4 && ds[2] <= 31) {
        cout << "Heisei\n";
    } else {
        cout << "TBD\n";
    }

    return 0;
}