#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;
using llong = long long;

pair<llong, llong> island[100005];

int main() {
    llong n, m;
    llong ans = 1;
    llong l, r;

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> island[i].first >> island[i].second;
    }
    sort(island, island + m);
    l = 0;
    r = n;
    for (int i = 0; i < m; i++) {
        if (r <= island[i].first || l >= island[i].second) {
            ans++;
            l = island[i].first;
            r = island[i].second;
        }
        else {
            l = max(l, island[i].first);
            r = min(r, island[i].second);
        }
    }
    
    cout << ans << endl;
    return 0;
}