#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll N, K;
    cin >> N >> K;
    vector<ll> a(N+1);
    rep(i, 1, N+1) cin >> a[i];

    // 累積和
    vector<ll> s(N+1, 0);
    rep(i, 1, N+1) s[i] = a[i] + s[i-1];

    // 部分列列挙
    vector<ll> sub;
    rep(l, 1, N+1){
        rep(r, l, N+1){
            sub.push_back(s[r]-s[l-1]);
        }
    }

    // bitの数をカウント
    ll ans = 0;
    for(ll i = 40; i >= 0; i--){
        ll c = 0;
        for(auto p : sub){
            if((p & (ans+(1LL<<i))) == (ans+(1LL<<i))) c++;
        }
        if(c >= K) ans += (1LL<<i);
    }

    cout << ans << endl;

    return 0;
}