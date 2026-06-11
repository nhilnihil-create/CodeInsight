#include <bits/stdc++.h>
using namespace std;
#define rep(i, m, n) for (int i = m; i < n; ++i)

int main() {
    int N; cin >> N;
    map<int, int> ma;
    rep(i, 0, N) {
        int a; cin >> a;
        ma[a]++;
    }
    int ans = 0;
    for(auto itr = ma.rbegin(); itr != ma.rend(); ++itr) {
        int v = itr -> first;
        int b = 1;
        while(b <= v) b *= 2;
        if(v == b - v) {
            ans += ma[v] / 2;
        } else {
            int n = min(ma[v], ma[b - v]);
            ma[b - v] -= n;
            ans += n;
        }
    }
    cout << ans << endl;
    return 0;
}
