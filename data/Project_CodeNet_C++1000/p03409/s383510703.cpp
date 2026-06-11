#include<bits/stdc++.h>
#include <numeric>

using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define erep(i, n) for (ll i = 0; i <= (ll)(n); ++i)
#define FOR(i,a,b) for (ll i = (a); i < (ll)(b); ++i)
#define EFOR(i,a,b) for (ll i = (a); i <= (ll)(b); ++i)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } }

typedef pair<int, int> P;

int main() {
    int n; cin >> n;
    vector<P> ab(n);
    vector<P> cd(n);
    rep(i, n) {
        int a,b; cin >> a >> b;
        ab[i] = make_pair(a, b);
    }
    sort(ab.begin(), ab.end());
    rep(i, n) {
        int a,b; cin >> a >> b;
        cd[i] = make_pair(a, b);
    }
    sort(cd.begin(), cd.end());

    vector<bool> used(n, false);
    int ans = 0;
    rep(i, n) {
        vector<P> tmp;
        rep(j, n) {
            if(cd[i].first > ab[j].first && !used[j]) {
                tmp.push_back(make_pair(ab[j].second, j));
            }
        }
        if(tmp.empty()) continue;
        sort(tmp.begin(), tmp.end(), greater<P>());
        rep(j, tmp.size()) {
            if(cd[i].second > tmp[j].first) {
                used[tmp[j].second] = true;
                ans++;
                break;
            }
        }
    }


    cout << ans << endl;

    return 0;
}
