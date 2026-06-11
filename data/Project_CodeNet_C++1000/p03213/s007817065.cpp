#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

vector<pair<ll,ll>> prime_factorize(ll N){
    vector<pair<ll,ll>> ret;
    for(ll a = 2; a * a <= N; a++){
        if(N % a != 0) continue;
        ll ex = 0;
        while(N % a == 0){
            ex++;
            N /= a;
        }
        ret.push_back({a, ex});
    }
    if(N != 1) ret.push_back({N, 1});
    return ret;
}

int main(){
    ll N;
    cin >> N;
    map<ll,ll> mp;
    rep(i, 2, N+1){
        auto v = prime_factorize(i);
        for(auto e : v){
            mp[e.first] += e.second;
        }
    }
    ll ans = 0;
    ll c2 = 0, c4 = 0, c14 = 0, c24 = 0, c74 = 0;
    for(auto p : mp){
        if(p.second >= 2) c2++;
        if(p.second >= 4) c4++;
        if(p.second >= 14) c14++;
        if(p.second >= 24) c24++;
        if(p.second >= 74) c74++;
    }
    for(auto p : mp){
        if(p.second >= 2){
            if(p.second >= 4) ans += (c4 - 1) * (c4 - 2) / 2;
            else ans += c4 * (c4 - 1) / 2;
            if(p.second >= 24) ans += (c24 - 1);
            else ans += c24; 
        }
        if(p.second >= 4){
            if(p.second >= 14) ans += (c14 - 1);
            else ans += c14;
        }
    }
    ans += c74;
    cout << ans << endl;
    return 0;
}