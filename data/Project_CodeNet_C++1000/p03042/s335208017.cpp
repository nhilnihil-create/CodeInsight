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

int main() {
    string S;
    cin >> S;

    int p1 = (S[0] - '0') * 10 + (S[1] - '0');
    int p2 = (S[2] - '0') * 10 + (S[3] - '0');

    bool isYYMM = false;
    if (1 <= p2 && p2 <= 12) {
        isYYMM = true;
    }

    bool isMMYY = false;
    if (1 <= p1 && p1 <= 12) {
        isMMYY = true;
    }

    if (isYYMM && isMMYY) {
        cout << "AMBIGUOUS" << endl;
    } else if (isYYMM) {
        cout << "YYMM" << endl;
    } else if (isMMYY) {
        cout << "MMYY" << endl;
    } else {
        cout << "NA" << endl;
    }

    return 0;
}
