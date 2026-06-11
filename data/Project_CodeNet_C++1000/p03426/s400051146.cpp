#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T>
using vec = std::vector<T>;

map<int, pair<int, int>> mp;
int H, W, D;
int ans[90010];

int main() {
    cin >> H >> W >> D;

    rep(i, H) rep(j, W) {
        int a;
        cin >> a;
        mp[a] = {i, j};
    }

    for(int i=1;i<=D;i++){
        ans[i] = 0;
        for(int j=i+D;j<=H*W;j+=D){
            ans[j] = ans[j-D] + abs(mp[j].first - mp[j-D].first) +
            abs(mp[j].second - mp[j-D].second);
        }
    }

    int Q;
    cin >> Q;
    rep(i, Q) {
        int l, r;
        cin >> l >> r;
        cout << ans[r]-ans[l] << endl;
    }
}