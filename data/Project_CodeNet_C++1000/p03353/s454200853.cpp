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
    string s;
    int k;
    cin >> s >> k;
    unordered_set<string> us;
    priority_queue<string> pq;
    int n = s.size();
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= k && i + j <= n; j++) {
            string ss = string(s.begin() + i, s.begin() + i + j);
            if (us.find(ss) != us.end()) continue;
            pq.push(ss);
            us.insert(ss);
            if (pq.size() > k) pq.pop();
        }
    }
    cout << pq.top() << endl;
}
