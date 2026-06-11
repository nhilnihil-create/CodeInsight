#include <algorithm>
#include <bitset>
#include <climits>
#include <complex>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <queue>
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <thread>
#include <tuple>
#include <type_traits>
#include <vector>

#include <stdio.h>

using ll = long long;
using namespace std;

vector<vector<bool>> v;

int main() {
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;

    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   function<bool(const pair<int, int>, const pair<int, int>)>>
        q([](const pair<int, int>& l, const pair<int, int> r) {
            return l.second > r.second;
        });

    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        q.emplace(a, b);
    }

    pair<int, int> p = q.top();
    q.pop();
    int last = p.second;
    int ans = 1;
    while (!q.empty()) {
        p = q.top();
        q.pop();
        if (p.first < last) {
            continue;
        } else {
            ans++;
            last = p.second;
        }
    }
    cout << ans << endl;

    return 0;
}
