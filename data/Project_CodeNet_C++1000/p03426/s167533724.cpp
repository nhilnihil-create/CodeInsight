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

    int n, m, D;
    cin >> n >> m >> D;

    vector<vector<pair<int,int>>> pos(D);
    vector<vector<int>> A(n, vector<int>(m, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int x;
            cin >> x;
            A[i][j] = x;
            pos[(x - 1) % D].emplace_back(i, j);
        }
    }

    auto cmp = [&](const pair<int,int>& l, const pair<int,int>& r) {
        return A[l.first][l.second] < A[r.first][r.second];
    };

    for (auto& V : pos) {
        sort(V.begin(), V.end(), cmp);
    }

    vector<vector<long long>> dis(D);

    for (int i = 0; i < D; ++i) {
        auto& P = pos[i];
        int n = P.size();
        auto& R = dis[i];
        for (int j = 0; j < n; ++j) {
            int d = 0;
            if (j - 1 >= 0) {
                d = abs(P[j].first - P[j - 1].first) + abs(P[j].second - P[j - 1].second);
                d += R.back();
            }
            // cout << i << " " << j << " " << d << endl;
            R.push_back(d);
        }
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;

        int d = (l - 1) % D;
        l = (l - 1) / D;
        r = (r - 1) / D;
        // cout << d << " " << l << " " << r << endl;
        cout << dis[d][r] - dis[d][l] << '\n';            
    }

    return 0;
}