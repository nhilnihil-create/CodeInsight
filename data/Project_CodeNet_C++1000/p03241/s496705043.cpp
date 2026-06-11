#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

vector<ll> yakusu(ll n){
    vector<ll> ret;
    for(ll i = 1; i*i <= n; i++){
        if(n % i != 0) continue;
        ret.push_back(i);
        if(i*i != n) ret.push_back(n/i);
    }
    sort(ret.begin(), ret.end());
    return ret;
}

int main(){
    ll N, M;
    cin >> N >> M;
    auto vec = yakusu(M);
    ll ans = 1;
    for(auto v : vec){
        if(v * N <= M) ans = max(ans, v);
    }
    cout << ans << endl;
    return 0;
}