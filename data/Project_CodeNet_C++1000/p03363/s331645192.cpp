#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll N;
    cin >> N;
    map<ll,ll> mp;
    mp[0] = 1;
    ll now = 0;
    rep(i, 0, N){
        ll a;
        cin >> a;
        now += a;
        mp[now]++;
    }
    ll ans = 0;
    for(auto p : mp){
        ans += p.second * (p.second - 1) / 2;
    }
    cout << ans << endl;
    return 0;
}