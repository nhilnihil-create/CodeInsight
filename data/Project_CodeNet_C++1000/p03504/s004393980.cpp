#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<n; i++)
#define pb push_back
#define int long long
typedef tuple<int, int, int> T;

int N, C;
vector<T> tsc;
int imos[100100];
set<int> S[35];

signed main() {
    cin >> N >> C;
    rep(i, N) {
        int s, t, c; cin >> s >> t >> c;
        tsc.pb(make_tuple(t, s, c));
    }
    sort(tsc.begin(), tsc.end());
    rep(i, N) {
        int t = get<0>(tsc[i]), s = get<1>(tsc[i]), c = get<2>(tsc[i]);
        if (S[c].find(s)==S[c].end()) {
            imos[s-1]++;
            imos[t]--;
        }
        else {
            imos[s]++;
            imos[t]--;
        }
        S[c].insert(t);
    }
    
    int ans = imos[0];
    
    for (int i=1; i<100100; i++) {
        imos[i] += imos[i-1];
        ans = max(ans, imos[i]);
    }
    
    cout << ans << endl;
}