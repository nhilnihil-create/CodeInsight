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

ll x[55], y[55];

int main(){
    int n, k;
    cin >> n >> k;
    rep(i, n) cin >> x[i] >> y[i];

    ll ans = 5e18;

    if (k == 2){
        for(int a = 0; a < n-1; a++){
            for(int b = a+1; b < n; b++){
                ll xmax = max({x[a],x[b]});
                ll xmin = min({x[a],x[b]});
                ll ymax = max({y[a],y[b]});
                ll ymin = min({y[a],y[b]});
                int cnt = 0;
                rep(i, n) if (xmin <= x[i] && x[i] <= xmax && ymin <= y[i] && y[i] <= ymax) cnt++;
                if (cnt >= k) ans = min(ans, (xmax-xmin)*(ymax-ymin));
            }
        }
    }



    else if (k == 3){
        for(int a = 0; a < n-2; a++){
            for(int b = a+1; b < n-1; b++){
                for(int c = b+1; c < n; c++){
                    ll xmax = max({x[a],x[b],x[c]});
                    ll xmin = min({x[a],x[b],x[c]});
                    ll ymax = max({y[a],y[b],y[c]});
                    ll ymin = min({y[a],y[b],y[c]});
                    int cnt = 0;
                    rep(i, n) if (xmin <= x[i] && x[i] <= xmax && ymin <= y[i] && y[i] <= ymax) cnt++;
                    if (cnt >= k) ans = min(ans, (xmax-xmin)*(ymax-ymin));
                }
            }
        }
    }


    else {
        for(int a = 0; a < n-3; a++){
            for(int b = a+1; b < n-2; b++){
                for(int c = b+1; c < n-1; c++){
                    for(int d = c+1; d < n; d++){
                        ll xmax = max({x[a],x[b],x[c],x[d]});
                        ll xmin = min({x[a],x[b],x[c],x[d]});
                        ll ymax = max({y[a],y[b],y[c],y[d]});
                        ll ymin = min({y[a],y[b],y[c],y[d]});
                        int cnt = 0;
                        rep(i, n) if (xmin <= x[i] && x[i] <= xmax && ymin <= y[i] && y[i] <= ymax) cnt++;
                        if (cnt >= k) ans = min(ans, (xmax-xmin)*(ymax-ymin));
                    }
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}
