#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main() {
    ll N, M;
    cin >> N >> M;
    vector<pair<ll,ll>>AB(N);
    for (int i=0; i<N; i++){
        ll ai, bi;
        cin >> ai >> bi;
        pair<ll,ll>ps;
        ps.first = ai;
        ps.second = bi;

        AB[i] = ps;
    }
    sort(all(AB));
    ll ans = 0;
    for (int i=0; i<N; i++){
        if (M <= 0)break;
        ll ai, bi;
        ai = AB[i].first;
        bi = AB[i].second;
        ans += ai * min(M,bi);
        M -= min(M,bi);
    }
    cout << ans << endl;
}