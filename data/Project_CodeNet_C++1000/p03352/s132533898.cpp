#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define VL vector<ll>
#define VS vector<string>
#define ALL(v) (v).begin(), (v).end()

//aでex回割れる
vector<pair<ll,ll>> prime_factorize(ll N){
    vector<pair<ll,ll>> ret;
    for(ll a = 2; a * a <=N; a++){
        ll tmp=N;
        if(tmp % a != 0) continue;
        ll ex = 0;
        while(tmp % a == 0){
            ex++;
            tmp /= a;
        }
        ret.push_back({a, ex});
    }
    if(N != 1) ret.push_back({N, 1});
    else ret.push_back({1, 2});
    return ret;
}
 
int main(){
    ll n;
    cin >> n;
    ll ans = 0;
    //
    for(ll i=(ll)(n); i>(ll)(0); i--){
        auto v = prime_factorize(i);
        ll tmp=0;
        for(auto e : v){
            if(e.second>=2){
                tmp=max( (ll)(pow(e.first,e.second)), tmp);
            }
            ans=max(tmp,ans);
        }
    }
    //
    cout << ans << endl;
    return 0;
}