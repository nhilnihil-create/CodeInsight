#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define ve vector
#define chmin(x,y) x = min(x,y)

int main(){
    int n,m;
    cin >> n >> m;
    set<P> ab,ba;
    rep(i,m){
        ll a,b;
        cin >> a >> b;
        ab.insert(P(a,b));
        ba.insert(P(b,a));
    }
    int ans = 0;
    
    while(!ab.empty()){
        auto it = ab.end();
        it--;
        P x = *it;
        ab.erase(it);
        ans++;
        auto it2 = ba.upper_bound(P(x.first+1, -1));
        while(it2 != ba.end()){
            x = *it2;
            it2 = ba.erase(it2);
            ab.erase(P(x.second,x.first));
        }
    }
    
    cout << ans << endl;
    return 0;
}
