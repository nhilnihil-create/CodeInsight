#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<deque>
#include<cmath>
#include<map>
#include<cstring>

using namespace std;
typedef long long ll;
const int INF = 1e9;
const ll MOD = 1e9 + 7;
const ll LLINF = 1LL<<60;
#define P pair<int, int>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define print(x) cout << (x) << endl

/*-- template --*/

int main() {
    int N, M, Q;
    cin >> N >> M >> Q;
    vector<vector<int>> G(500);
    rep(i, M) {
        int l, r; cin >> l >> r;
        --l, --r;
        G[l].pb(r);
    }
    rep(i, N) {
        if(!G[i].empty())
            sort(G[i].begin(), G[i].end());
    }
    int p[Q], q[Q];
    rep(i, Q) {
        cin >> p[i] >> q[i];
        --p[i];
    }
    int answer[Q];
    rep(i, Q) {
        int ans = 0;
        for(int j = p[i]; j < q[i]; ++j) {
            if(!G[j].empty())
                ans += upper_bound(G[j].begin(), G[j].end(), q[i] - 1) - G[j].begin();
        }
        answer[i] = ans;
    }
    rep(i, Q)
        cout << answer[i] << endl;
}
