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

    int n, K;
    cin >> n >> K;
    string s;
    cin >> s;

    int res = 0;
    vector<pair<int,int>> P;
    for (int i = 0; i < n; ++i) {
        int x = s[i] - '0';
        int cnt = 1;
        while (i + 1 < n && s[i + 1] == s[i]) {
            ++i;
            ++cnt;
        }
        P.emplace_back(x, cnt);
        if (x == 1) {
            res = max(res, cnt);
        }
    }

    int N = P.size();

    int sum = 0;
    for (int i = 0, j = 0, k = 0; i < N; ++i) {
        sum += P[i].second;
        if (P[i].first == 0) {
            ++k;
        }
        while (k > K) {
            if (P[j].first == 0) {
                --k;
            }
            sum -= P[j].second;
            ++j;
        }
        res = max(res, sum);
    }
    cout << res << "\n";

    return 0;
}