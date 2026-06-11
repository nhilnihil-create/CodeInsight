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

    int n, m;
    cin >> n; 
    cin >> m;
    vector<int> P(n);
    for (int i = 0; i < n; ++i) {
        cin >> P[i];
        --P[i];
    }
    vector<int> X(m);
    vector<int> Y(m);
    for (int i = 0; i < m; ++i) {
        cin >> X[i] >> Y[i];
        --X[i], --Y[i];
    }
    
    vector<vector<int>> graph(n);
    for (int i = 0; i < m; ++i) {
        graph[X[i]].push_back(Y[i]);
        graph[Y[i]].push_back(X[i]);
    }
    vector<int> clock(n, 0);
    
    int res = 0;
    int clk = 0;
    for (int i = 0; i < n; ++i) {
        if (clock[i] == 0) {
            vector<int> que;
            que.push_back(i);
            clock[i] = ++clk;

            for (int j = 0; j < que.size(); ++j) {
                int u = que[j];
                for (auto v : graph[u]) {
                    if (clock[v] == 0) {
                        clock[v] = clk;
                        que.push_back(v);
                    }
                }
            }


            for (auto x : que) {
                if (clock[P[x]] == clk) {
                    ++res;
                }
            }
        }
    }

    cout << res << '\n';


    return 0;
}