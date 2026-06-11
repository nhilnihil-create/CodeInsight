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

ll dp[100010];
ll a[305][305];
ll l[100010];
ll r[100010];
P p[100010];


int main(){
    int h, w, d;
    cin >> h >> w >> d;
    rep(i, h) rep(j, w){
        ll t;
        cin >> t;
        t--;
        p[t] = make_pair(i,j);
    }




    int q;
    cin >> q;
    rep(i, q) {
        cin >> l[i] >> r[i];
        l[i]--;
        r[i]--;
    }

    rep(i, d){
        for(int j = i; j < h*w-d; j += d){
            dp[j+d] = dp[j] + abs(p[j].first - p[j+d].first) +  abs(p[j].second - p[j+d].second);
        }
    }

    rep(i, q){
        cout << dp[r[i]] - dp[l[i]] << endl;
    }

    return 0;
}