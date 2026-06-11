#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    ll N,K;
    cin >> N >> K;
    vector<ll> x(N);
    vector<ll> y(N);
    rep(i,N) cin >> x[i] >> y[i];
    ll ans = 4000000000000000001;
    for (ll i = 0; i < N; i++){
        for (ll j = i + 1; j < N; j++){
            for (ll k = 0; k < N; k++){
                for (ll l = k + 1; l < N; l++){
                    ll ans_sub = abs(y[l] - y[k]) * abs(x[j] - x[i]);
                    ll cnt = 0;
                    rep(m,N){
                        ll min_x = min(x[i], x[j]);
                        ll max_x = max(x[i], x[j]);
                        ll min_y = min(y[k], y[l]);
                        ll max_y = max(y[k], y[l]);
                        if (min_x <= x[m] && x[m] <= max_x && min_y <= y[m] && y[m] <= max_y){
                            cnt++;
                        }
                        if (cnt >= K) ans = min(ans, ans_sub);
                    }
                }
            }
        }
    }
    cout << ans << endl;
}
