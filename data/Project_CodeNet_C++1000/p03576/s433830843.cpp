#include <bits/stdc++.h>
using namespace std;
#define REP(i,a) for(int i = 0; i < (a); i++)
#define ALL(a) (a).begin(),(a).end()
typedef long long ll;
typedef pair<ll, ll> P;
const int INF = 1e9;
const long long LINF = 1e18;
const long long MOD = 1e9 + 7;

signed main(){
    int n,K;
    cin >> n >> K;
    vector<ll> x, y;
    vector<P> v(n);
    REP(i,n){
        cin >> v[i].first >> v[i].second;
        x.emplace_back(v[i].first);
        y.emplace_back(v[i].second);
    }
    sort(ALL(x));
    sort(ALL(y));
    ll ans = LLONG_MAX;
    REP(i,n){
        for(int j = i + 1; j < n; j++){
            REP(k,n){
                for(int l = k + 1; l < n; l++){
                    ll x_left = x[i], x_right = x[j], y_bottom = y[k], y_top = y[l];
                    int cnt = 0;
                    REP(m,n){
                        if(x_left <= v[m].first && v[m].first <= x_right && y_bottom <= v[m].second && v[m].second <= y_top){
                            cnt++;
                        }
                    }
                    if(cnt >= K){
                        ans = min(ans, abs(x_right - x_left) * abs(y_top - y_bottom));
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}