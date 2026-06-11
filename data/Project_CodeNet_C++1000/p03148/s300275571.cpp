#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <set>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    int n, k, b[100005] = {};
    vector<int> c = {};
    ll z = 0, y = 0, w = 0;
    multiset<int, greater<int>> t = {0};
    pii a[100005] = {};
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i].second >> a[i].first;
    sort(a + 1, a + n + 1); reverse(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
        if (!b[a[i].second] && c.size() < k) c.push_back(a[i].first), y += a[i].first;
        else t.insert(a[i].first);
        b[a[i].second] = 1;
    }
    sort(c.begin(), c.end()); reverse(c.begin(), c.end());
    int m = (int)c.size();
    while (m < k) y += *t.begin(), t.erase(t.begin()), m++;
    z = y + 1ll * c.size() * c.size();
    for (int i = (int)c.size() - 1; i >= 0 && !t.empty(); i--) {
        y -= c[i];
        y += *t.begin();
        t.erase(t.begin());
        z = max(z, y + 1ll * i * i);
    }
    cout << z;
}
