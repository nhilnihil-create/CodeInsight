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
    ll n;
    cin >> n;
    ll ans = 0;
    rep(i, 1, n+1) {
        ll tmp = 0;
        auto v = yakusu(i);
        for(auto e : v) tmp += e % 2;
        ans += (tmp == 8);
    }
    cout << ans << endl;
    return 0;
}