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
    vector<int> T(n);
    vector<int> D(n);

    vector<vector<int>> X(n);
    for (int i = 0; i < n; ++i) {
        cin >> T[i] >> D[i];
        --T[i];
        X[T[i]].push_back(D[i]);
    }
    for (auto& V : X) {
        sort(V.begin(), V.end(), greater<int>());
    }

    sort(X.begin(), X.end(), greater<vector<int>>());
    while (!X.empty() && X.back().empty()) {
        X.pop_back();
    }

    priority_queue<int, vector<int>, greater<int>> pq;

    long long res = 0;
    long long sum = 0;
    for (int i = 0; i < X.size(); ++i) {
        if (i + 1 > K) {
            break;
        }

        sum += X[i].front();

        for (int j = 1; j < X[i].size(); ++j) {
            sum += X[i][j];
            pq.push(X[i][j]);
        }
        while (i + 1 + pq.size() > K) {
            sum -= pq.top();
            pq.pop();
        }

        res = max(res, (i + 1) * 1LL * (i + 1) + sum);
    }

    cout << res << '\n';

    return 0;
}