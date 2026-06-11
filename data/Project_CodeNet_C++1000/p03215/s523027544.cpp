#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
#define REP(i,n) for (ll i = 0; i < (n); ++i)

int main(){
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    REP(i, n){
        cin >> a.at(i);
    }
    vector<ll> cs(n);
    cs.at(0) = a.at(0);
    for(ll i = 1; i < n; ++i){
        cs.at(i) = cs.at(i - 1) + a.at(i);
    }

    vector<ll> cands;
    REP(i, n){
        for(ll j = 1; i + j <= n; ++j){
            ll tmp = cs.at(i + j - 1);
            if(i > 0){
                tmp -= cs.at(i - 1);
            }
            cands.push_back(tmp);
        }
    }

    for(ll i = 40; i >= 0; --i){
        vector<ll> nxt;
        for(ll c : cands){
            if((c >> i) & 1){
                nxt.push_back(c);
            }
        }
        if(nxt.size() >= k){
            cands.swap(nxt);
        }
    }

    ll ans = cands.at(0);
    for(ll i = 1; i < k; ++i){
        ans &= cands.at(i);
    }
    cout << ans << endl;
    return 0;
}
