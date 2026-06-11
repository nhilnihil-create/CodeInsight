#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=(ll)1e9+7;

int main() {
    int N,K; cin>>N>>K;
    vector<ll> a(N,0);
    for (int i = 0; i < N; ++i) {
        cin>>a[i];
    }

    vector<ll> subtotal;
    for (int i = 0; i < N; ++i) {
        ll tmp=a[i];
        subtotal.push_back(tmp);
        for (int j = i+1; j < N; ++j) {
            tmp+=a[j];
            subtotal.push_back(tmp);
        }
    }
    ll ans=0ll;
    for (int i = 39; i >= 0; --i) {
        int cnt=0;
        ll cmp=ans+(1ll<<i);
        for(ll s:subtotal){
            if((s&cmp)==cmp) ++cnt;
        }
        if(cnt>=K) ans=cmp;
    }
    cout<<ans<<endl;
    return 0;
}
