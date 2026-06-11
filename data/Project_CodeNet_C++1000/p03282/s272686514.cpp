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

    long long K;
    cin >> K;

    const int N = 62;
    const long long INF = 1LL << 62;
    vector<vector<long long>> lens(10, vector<long long>(N + 1, 1));

    for (int i = 2; i <= 9; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (lens[i][j - 1] > INF / i) {
                lens[i][j] = INF;
                continue;
            }
            lens[i][j] = lens[i][j - 1] * i;
        }
    }

    int n = s.length();
    long long rem = K - 1;
    int res = -1;
    for (int i = 0; i < n; ++i) {
        if (lens[s[i] - '0'][N] <= rem) {
            rem -= lens[s[i] - '0'][N];
        } else {
            res = s[i] - '0';
            break;
        }
    }

    cout << res << '\n';

    return 0;
}