#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <queue>
#include <cmath>
using namespace std;

int main() {        
    int k;
    cin >> k;
    int res = 1;
    vector<int> v1(1, 1), v2;
    vector<int> visited(k, 0);
    visited[1] = 1;

    while (v1.size() > 0) {
        v2 = v1;
        for (auto node : v1) {
            node = node * 10 % k;
            while (visited[node] == 0) {
                visited[node] = 1;
                v2.push_back(node);
                node = node * 10 % k;
            }
        }
        for (auto node : v2) {
            if (node == 0) {
                cout << res << endl;
                return 0;
            }
            node = (node + 1) % k;
            if (visited[node] == 0) {
                visited[node] = 1;
                v1.push_back(node);
            }
        }
        res++;
    }
    cout << res << endl;
}


