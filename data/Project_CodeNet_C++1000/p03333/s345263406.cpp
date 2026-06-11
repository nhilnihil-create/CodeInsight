#include <iostream>
#include <vector>
#include <array>
#include <deque>
#include <stack>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <numeric>
#include <utility>
#include <cmath>
#include <iomanip>
#include <cassert>
#include <complex>
#include <bitset>
#include <functional>

using namespace std;
using ll=long long int;

ll calc(const vector<pair<int, int>> &s) {
    int n = s.size();
    priority_queue<int> l;
    priority_queue<int, vector<int>, greater<int>> r;
    for (int i = 0; i < n; ++i) {
        l.push(s[i].first);
        r.push(s[i].second);
    }

    int c = 0;
    ll ans = 0;
    while (true) {
        if (l.top() <= c) break;
        ans += l.top() - c;
        c = l.top();
        l.pop();
        if (r.top() >= c) break;
        ans += c - r.top();
        c = r.top();
        r.pop();
    }

    return ans + abs(c);
}

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> s(n);
    for (auto &e: s) cin >> e.first >> e.second;

    ll ans = 0;
    ans = max(ans, calc(s));
    for (auto &e: s) {
        swap(e.first, e.second);
        e.first *= -1;
        e.second *= -1;
    }
    ans = max(ans, calc(s));

    cout << ans << endl;

    return 0;
}
