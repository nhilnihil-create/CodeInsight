#include<bits/stdc++.h>
#define rep(i, n) for (int i=0;i<(n);i++)
using namespace std;
typedef long long ll;

ll INF = 1e12;
 
int main(void){
    int n;
    cin>>n;
    vector<ll> v(n);
    rep(i, n) cin>>v[i];
    int minus = 0;
    ll maxminus = INF;
    bool ok = false;
    rep(i, n) {
        maxminus = min(maxminus, abs(v[i]));
        if(v[i]<0) {
            minus++;
        }
        else if(v[i] == 0) ok = true;
    }
    ll ans = 0;
    if(minus%2 == 0 || ok) {
        rep(i, n) ans+=abs(v[i]);
    } 
    else{
        rep(i, n) ans += abs(v[i]);
        ans -= 2*abs(maxminus);
    }
    cout<<ans<<endl;
    return 0;
}