#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for(int i = n-1; i >= 0; i--)
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
typedef long long ll;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<vector<int>>;
using VL = vector<ll>;
using VVL = vector<vector<ll>>;
using VP = vector<P>;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return true; } return false; }

int main(){
    int h, w, d;
    cin >> h >> w >> d;
    VVI a(h, VI(w));
    rep(i,h)rep(j,w) cin >> a[i][j];

    VP c(h * w + 1);
    rep(i,h) rep(j,w){
        P p = P(i, j);
        c[a[i][j]] = p;
    }

    VL cost(h * w + 1, -1);
    for(int i = 0; i <= h * w; i++){
        if (cost[i] != -1) continue;
        cost[i] = 0;
        P pre = c[i];
        for(int j = i+d; j <= h * w; j += d){
            P now = c[j];
            cost[j] = cost[j-d] + abs(now.first - pre.first) + abs(now.second - pre.second);
            pre = now;
        }
    }

    int q;
    cin >> q;
    rep(i,q){
        int l, r;
        cin >> l >> r;
        ll ans = cost[r] - cost[l];
        cout << ans << endl;
    }
    return 0;
}