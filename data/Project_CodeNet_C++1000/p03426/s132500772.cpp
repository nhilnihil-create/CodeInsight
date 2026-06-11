#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)
using namespace std;
typedef long long ll;
typedef pair<int, int> P; 
const int inf = 1<<21;
const ll INF = 1LL << 60;
const ll mod = 1e9+7;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};

int main() {
    int h, w, d;
    cin >> h >> w >> d;
    vector<vector<int>> a(h, vector<int>(w));
    vector<pair<int, int>> xy(h*w+1);
    rep(i, h)rep(j, w) {
        cin >> a[i][j];
        xy[a[i][j]] = make_pair(i, j);
    }

    vector<ll> b(h*w+1, 0LL);
    for(int i=d+1; i<=h*w; i++){
        ll x = xy[i].first, y = xy[i].second;
        ll px = xy[i-d].first, py = xy[i-d].second;
        b[i] = b[i-d] + abs(x-px) + abs(y-py);
    }
    int q;
    cin >> q;
    rep(i, q){
        int l, r;
        cin >> l >> r;
        cout << b[r] - b[l] << endl;
    }

    return 0;
}