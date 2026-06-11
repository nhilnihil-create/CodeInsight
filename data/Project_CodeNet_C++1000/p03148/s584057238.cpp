#include <numeric>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int main() {
    int n, k; cin >> n >> k;
    vector<int> vals[n];
    for (int i = 0; i < n; i++) {
        int t, d; cin >> t >> d;
        vals[t-1].push_back(d);
    }
    vector<int> rest, top;
    for (int i = 0; i < n; i++) {
        vector<int> &v = vals[i];
        if (!v.empty()) {
            sort(v.begin(), v.end());
            top.push_back(v.back());
            rest.insert(rest.end(), v.begin(), prev(v.end()));
        }
    }
    sort(top.rbegin(), top.rend());
    sort(rest.begin(), rest.end());
    if (top.size() > k) top.resize(k);
    long long sum = accumulate(top.begin(), top.end(), 0LL), count = top.size();
    for (int i = 0; i < k - top.size(); i++) {
        sum += rest.back();
        rest.pop_back();
    }
    long long ans = sum + count * count;
    while (!top.empty() && !rest.empty() && count > 0) {
        count--;
        sum += rest.back() - top.back();
        rest.pop_back(); top.pop_back();
        ans = max(ans, sum + count * count);
    }
    cout << ans << endl;
}
