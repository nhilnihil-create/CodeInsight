#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> graph[n + 1];
    int deg[n + 1] = {}, x[n + 1];
    fill(x, x + n + 1, -1);
    for (int l, r, d; cin >> l >> r >> d; ) {
        graph[l].emplace_back(r, d);
        deg[r]++;
    }
    string result = "Yes";
    stack<int> stack;
    for (int i = 1; i <= n; i++) {
        if (deg[i] == 0) {
            stack.emplace(i);
            x[i] = 0;
        }
    }
    while (!stack.empty()) {
        auto top = stack.top();
        stack.pop();
        for (auto& p : graph[top]) {
            if (deg[p.first] > 0) {
                deg[p.first]--;
                if (deg[p.first] == 0) {
                    stack.emplace(p.first);
                }
            }
            if (x[p.first] != -1 && x[p.first] - x[top] != p.second) {
                result = "No";
            } else {
                x[p.first] = x[top] + p.second;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (deg[i] > 0) {
            result = "No";
        }
    }
    cout << result;
    return 0;
}