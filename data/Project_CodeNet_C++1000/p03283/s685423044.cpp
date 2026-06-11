#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
using Graph = vector<vector<int>>;
#define MOD 1000000007
#define MOD2 998244353
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;

int l[200010], r[200010];
int p[100010], q[100010];

int mp[505][505];

int main(){
    int n, m, Q;
    cin >> n >> m >> Q;
    rep(i, m) cin >> l[i] >> r[i];
    rep(i, Q) cin >> p[i] >> q[i];

    rep(i, m){
        mp[r[i]][l[i]]++;
    }

    rep(i, n + 1){
        rep(j, n + 1){
            mp[i][j+1] += mp[i][j];
        }
    }

    // rep(i, n+2){
    //     rep(j, n+2) cout << mp[i][j] << " ";
    //     cout << endl;
    // }
    vector<int> ans;

    rep(i, Q){
        int tmp = 0;
        for (int t = p[i]; t <= q[i]; t++){
            tmp += mp[t][q[i] + 1] - mp[t][p[i] - 1];
        }
        ans.push_back(tmp);
    }
    rep(i, Q) cout << ans[i] << endl;

    return 0;
}