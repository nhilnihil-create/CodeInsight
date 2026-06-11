#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
 
const double EPS = 1e-10;
const ll INF = 100000000;
const ll MOD = 1000000007;

ll h, w, n;
vector<int> vec[200000];

int main() {
    cin >> h >> w >> n;
    rep(i,n) {
        int x, y; cin >> x >> y;
        x--; y--;
        vec[y].push_back(x);
    }
    rep(i,w) sort(vec[i].begin(), vec[i].end());
    int pos = 0;
    int ans = h;
    rep(i,w) {
        rep(j,vec[i].size()) {
            if (i+pos == vec[i][j]) pos++;
            else if (i+pos < vec[i][j]) ans = min(ans, vec[i][j]); 
        }
    }
    cout << ans << endl;
}

