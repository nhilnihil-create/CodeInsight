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

ll v[55];

int main(){
    int n, k;
    cin >> n >> k;
    rep(i, n) cin >> v[i];

    ll ans = 0;
    int h = min(n, k);
    for(int g = 0; g <= h; g++){
        for(int l = 0; l <= g; l++){
            vector<ll> tmp;
            rep(i, l) tmp.push_back(v[i]);
            rep(i, g - l) tmp.push_back(v[n - i - 1]);

            sort(tmp.begin(), tmp.end());
            ll s = 0;

            // rep(i, tmp.size()) cout << tmp[i] << " ";
            // cout << endl;

            rep(p, tmp.size()) s += tmp[p];
            int thr = min(k - g, (int)tmp.size());
            rep(q, thr) if(tmp[q] < 0) s -= tmp[q];
            // cout << "s=" << s << endl;
            
            ans = max(ans, s);
        }
    }
    cout << ans << endl;
    return 0;
}