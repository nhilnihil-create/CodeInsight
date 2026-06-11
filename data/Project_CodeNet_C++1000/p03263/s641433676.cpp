#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); ++i)
#define repr(i, n) for(int i = (n-1); i >= 0; --i)

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

typedef long long ll;
typedef pair<int, int> P;

const int MAX = 200005;
const int INF = 1001001001;
const int MOD = 1000000007;

int main(){
    int H, W;
    cin >> H >> W;

    vector<vector<int>> a(H, vector<int>(W));
    rep(i, H)rep(j, W) cin >> a[i][j], a[i][j] %= 2;

    vector<pair<P, P>> ans;
    rep(i, H)rep(j, W) {
        if (a[i][j]) {
            if (j+1 < W) {
                a[i][j] = 0;
                a[i][j+1] ^= 1;
                ans.emplace_back(P(i, j), P(i, j+1));
            } else if (i+1 < H) {
                a[i][j] = 0;
                a[i+1][j] ^= 1;
                ans.emplace_back(P(i, j), P(i+1, j));
            }
        }
    }

    cout << ans.size() << endl;
    for (auto &i : ans) cout << i.first.first+1 << " " << i.first.second+1 << " " << i.second.first+1 << " " << i.second.second+1 << endl;
}