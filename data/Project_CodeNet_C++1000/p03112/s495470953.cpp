#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main(){
    ll A, B, Q; cin >> A >> B >> Q;
    vector<ll> S(A), T(B);
    for(int i = 0; i < A; i++) cin >> S[i];
    for(int i = 0; i < B; i++) cin >> T[i];
    for(int i = 0; i < Q; i++){
        ll x; cin >> x;
        ll ans = 1e18;
        auto itrs = lower_bound(S.begin(), S.end(), x);
        auto itrt = lower_bound(T.begin(), T.end(), x);
        int idxs = distance(S.begin(), itrs);
        int idxt = distance(T.begin(), itrt);
        if(idxs < A && idxt < B) ans = min(max(S[idxs], T[idxt])-x, ans);
        //cout << ans << endl;
        if(idxs >= 1 && idxt >= 1)ans = min(x-min(S[idxs-1], T[idxt-1]), ans);
        //cout << ans << endl;
        if(idxs < A && idxt >= 1)ans = min(ans, 2*min(S[idxs]-x, x-T[idxt-1]) + max(S[idxs]-x, x-T[idxt-1]) );
        //cout << ans << endl;
        if(idxs >= 1 && idxt < B)ans = min(ans, 2*min(x-S[idxs-1], T[idxt]-x) + max(x-S[idxs-1], T[idxt]-x) );
        
        cout << ans << endl;
    }
}
