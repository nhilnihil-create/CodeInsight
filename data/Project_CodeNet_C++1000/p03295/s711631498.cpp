//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using P = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;



int main() {
    int n, m;
    cin >> n >> m;
    vector<P> you(m);
    rep(i, m) {
        cin >> you[i].second >> you[i].first;
    }

    sort(all(you));
    int ans = 0;
    int j = 0;
    rep(i, m) {
        if(you[i].second >= j) {
            ans++;
            j = you[i].first;
        }
    }

    cout << ans << endl;
}