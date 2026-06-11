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

    int cnt = 0;
    for (int i = 0; i < S.size(); i++) {
        if (S[i] == '0') {
            ++cnt;
        } else {
            --cnt;
        }
    }

    cout << S.size() - abs(cnt) << endl;

    return 0;
}
