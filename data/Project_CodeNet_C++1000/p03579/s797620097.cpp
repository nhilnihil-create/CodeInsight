#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#include <chrono>

using namespace std;

int main(int argc, const char * argv[]) {
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int64_t n, m; cin >> n >> m;
    
    vector<vector<int>> edge(n, vector<int>());
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b; a--; b--;
        edge.at(a).push_back(b);
        edge.at(b).push_back(a);
    }
    
    vector<int> color(n, -1);
    color.at(0) = 0;
    
    queue<int> q;
    q.push(0);
    
    bool is_bipartite = true;
    while (!q.empty() && is_bipartite) {
        int v = q.front();
        q.pop();
        
        int c = color.at(v);
        for (int i : edge.at(v)) {
            if (color.at(i) == c) {
                is_bipartite = false;
                break;
            } else if (color.at(i) == 1 - c) continue;
            else {
                color.at(i) = 1 - c;
                q.push(i);
            }
        }
    }
    
    if (is_bipartite) {
        int64_t a = 0;
        for (int i = 0; i < n; i++) a += color.at(i);
        cout << n * (n - 1) / 2 - a * (a - 1) / 2 - (n - a) * (n - a - 1) / 2 - m << endl;
    } else {
        cout << n * (n - 1) / 2 - m << endl;
    }
    
    return 0;
}
