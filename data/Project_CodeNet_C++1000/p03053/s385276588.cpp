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

int cost[1010][1010];
string s[1010];

int main(){
    int h, w;
    cin >> h >> w;
    rep(i, h) cin >> s[i];

    rep(i, h) rep(j, w) {
        if (s[i][j] == '.') cost[i][j] = INF;
        else if (s[i][j] == '#') cost[i][j] = 0;
    }

    rep(i, h){
        for(int j = 1; j < w; j++){
            cost[i][j] = min(cost[i][j], cost[i][j-1]+1);
            if (i > 0) cost[i][j] = min(cost[i][j], cost[i-1][j]+1);
            if (i < h-1) cost[i][j] = min(cost[i][j], cost[i+1][j]+1);
        }
    }
    rep(i, h){
        for(int j = w - 2; j >= 0; j--){
            cost[i][j] = min(cost[i][j], cost[i][j+1]+1);
            if (i > 0) cost[i][j] = min(cost[i][j], cost[i-1][j]+1);
            if (i < h-1) cost[i][j] = min(cost[i][j], cost[i+1][j]+1);
        }
    }

    rrep(i, h){
        for(int j = 1; j < w; j++){
            cost[i][j] = min(cost[i][j], cost[i][j-1]+1);
            if (i > 0) cost[i][j] = min(cost[i][j], cost[i-1][j]+1);
            if (i < h-1) cost[i][j] = min(cost[i][j], cost[i+1][j]+1);
        }
    }
    rrep(i, h){
        for(int j = w - 2; j >= 0; j--){
            cost[i][j] = min(cost[i][j], cost[i][j+1]+1);
            if (i > 0) cost[i][j] = min(cost[i][j], cost[i-1][j]+1);
            if (i < h-1) cost[i][j] = min(cost[i][j], cost[i+1][j]+1);
        }
    }


    int ans = 0;
    rep(i, h){
        rep(j, w)  {
            ans = max(ans, cost[i][j]);
            // cout << cost[i][j] << " ";
        }
        // cout << endl;
    }

    cout << ans << endl;

    return 0;
}
