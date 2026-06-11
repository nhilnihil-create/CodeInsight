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
    string S;
    cin >> S;

    int year = 0;
    for (int i = 0; i < 4; i++) {
        year = year * 10 + (S[i] - '0');
    }

    int month = (S[5] - '0') * 10 + (S[6] - '0');
    int day =  (S[7] - '0') * 10 + (S[8] - '0');

    bool heisei = false;
    if (year < 2019) {
        heisei = true;
    } else if (year == 2019) {
        if (month <= 4) {
            heisei = true;
        }
    }

    if (heisei) {
        cout << "Heisei" << endl;
    } else {
        cout << "TBD" << endl;
    }

    return 0;
}