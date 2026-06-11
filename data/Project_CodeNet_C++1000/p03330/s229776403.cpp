#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;
const int MOD = 1000000007;
const int MOD2 = 998244353;

vector<int> color[3];
int d[35][35];
ll cost[3][35]; // グループiをc色に塗り替えるコスト

int main(){
    int n, c;
    cin >> n >> c;

    rep(i, c) rep(j, c) {
        cin >> d[i][j]; 
    }

    rep(i, n) rep(j, n){
        int a;
        cin >> a;
        a--;
        color[(i+j)%3].push_back(a);
    }

    rep(g, 3){
        rep(i, c) {
            ll tmp = 0;
            rep(j, color[g].size()){
                tmp += d[color[g][j]][i];
            }
            cost[g][i] = tmp;
        }
    }

    ll ans = LINF;

    rep(i, c) rep(j, c) rep(k, c){
        if (i == j || j == k || k == i) continue;
        ans = min(cost[0][i] + cost[1][j] + cost[2][k], ans);
    }

    cout << ans << endl;

    return 0;
}
