#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<n; i++)
#define pb push_back
#define int long long
typedef pair<int, int> P;

int N, K;
vector<P> l;
set<int> s;
vector<int> rem;
vector<int> add;

signed main() {
    cin.tie(0); ios::sync_with_stdio(false);
    cin >> N >> K;
    rep(i, N) {
        int t, d; cin >> t >> d;
        l.pb(P(d, t));
    }
    sort(l.begin(), l.end());
    reverse(l.begin(), l.end());
    
    int now_tast = 0;
    rep(i, K) {
        now_tast += l[i].first;
        if (s.find(l[i].second)!=s.end()) rem.pb(l[i].first);
        else s.insert(l[i].second);
    }
    int now_vari = s.size();
    for (int i=K; i<N; i++) {
        if (s.find(l[i].second)==s.end()) {
            add.pb(l[i].first);
            s.insert(l[i].second);
        }
    }
    
    sort(rem.begin(), rem.end());
    sort(add.begin(), add.end());
    reverse(add.begin(), add.end());
    int ans = now_tast+now_vari*now_vari;
    rep(i, min(rem.size(), add.size())) {
        now_tast += add[i]-rem[i];
        now_vari++;
        ans = max(ans, now_tast+now_vari*now_vari);
    }
    cout << ans << endl;
}