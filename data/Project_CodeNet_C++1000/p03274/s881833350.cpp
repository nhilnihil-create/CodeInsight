#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF (1LL<<50)
#define MOD 1000000007

int main(){
    ll N,K;
    cin >> N >> K;
    vector<ll> xm,xp;
    rep(i,N){
        ll x;
        cin >> x;
        if(x<0){
            xm.push_back(x);
        }else{
            xp.push_back(x);
        }
    }
    ll sz = xm.size();
    if(sz==0){
        cout << xp[K-1] << endl;
        return 0;
    }
    ll lim = min(K,sz);
    ll ans = INF;
    sort(xm.rbegin(),xm.rend());
    for(int i=0;i<lim;i++){
        if(xp.size()<=K-i-2) continue;
        ans = min(ans,2*abs(xm[i])+xp[K-i-2]);
        ans = min(ans,abs(xm[i])+2*xp[K-i-2]);
    }
    if(xp.size()>=K) ans = min(ans,xp[K-1]);
    if(sz>=K) ans = min(ans,abs(xm[K-1]));
    cout << ans << endl;
    return 0;
}