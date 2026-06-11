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

    int n;
    cin >> n;
    vector<int> C(n);
    vector<int> S(n);
    vector<int> F(n);
    for (int i = 0; i + 1 < n; ++i) {
        cin >> C[i] >> S[i] >> F[i];
    }


    vector<long long> res(n, 0);
    for (int i = n - 2; i >= 0; --i) {
        long long t = S[i] + C[i];
        for (int j = i + 1; j + 1 < n; ++j) {
            t = (max(t, (long long)S[j]) + F[j] - 1) / F[j] * 1LL * F[j] + C[j];
        }
        res[i] = t;
    }

    for (int i = 0; i < n; ++i) {
        cout << res[i] << '\n';
    }

    return 0;
}