#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    vector<int> a(n);
    for (auto &ai: a) cin >> ai;
    map<long long, int> cnt;
    cnt[0] = 1;
    long long acc = 0, ans = 0;
    for (int ai: a) acc += ai, ans += cnt[acc %= m]++;
    cout << ans << endl;
    return 0;
}
