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
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int res = 0x3f3f3f3f;
    for (int i = 0; i < n; i++) {
        priority_queue<int> pq1, pq2;
        for (int j = 0; j < n; j++) {
            if (v[j] < v[i]) {
                while (pq1.size() > 0) pq1.pop();
            } else {
                pq1.push(-v[j]);
                if (pq1.size() >= k) {
                    int t = -pq1.top();
                    pq1.pop();
                    pq2.push(t);
                }
            }
        }
        if (pq2.size() >= q) {
            while (pq2.size() > q) pq2.pop();
            res = min(res, pq2.top() - v[i]);
        }
    }
    cout << res << endl;
}







