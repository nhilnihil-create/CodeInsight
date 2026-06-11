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
    int c;
    cin >> c;
    vector<int> S(n);
    vector<int> T(n);
    vector<int> C(n);
    for (int i = 0; i < n; ++i) {
        cin >> S[i] >> T[i] >> C[i];
        --C[i];
    }

    map<int,int> cnts;

    vector<vector<pair<int,int>>> P(c);

    for (int i = 0; i < n; ++i) {
        P[C[i]].emplace_back(S[i], T[i]);
    }
    for (auto& V : P) {
        sort(V.begin(), V.end());
    }

    for (auto& V : P) {
        int n = V.size();
        for (int i = 0; i < n; ++i) {
            int l = V[i].first;
            int r = V[i].second;
            while (i + 1 < n && V[i + 1].first == r) {
                r = V[++i].second;
            }
            cnts[l * 2 - 1] += 1;
            cnts[r * 2] -= 1;
        }
    }

    int res = 0;
    int sum = 0;
    for (auto& p : cnts) {
        sum += p.second;
        res = max(res, sum);
    }
   
    cout << res << '\n';

    return 0;
}