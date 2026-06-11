#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int N;  cin >> N;
    vector<ll> a(N), b(N);
    for(int i=0; i<N; i++) cin >> a[i];
    for(int i=0; i<N; i++) cin >> b[i];

    ll ans = 0;
    for(ll k=0; k<29; k++){
        ll T  = ((ll)1 << k);
        vector<ll> bb(N);
        for(int i=0; i<N; i++){
            bb[i] = b[i]%(2*T);
        }
        sort(bb.begin(), bb.end());

        ll cnt = 0;
        for(int i=0; i<N; i++){
            ll aa = a[i]%(2*T);
            cnt += lower_bound(bb.begin(), bb.end(), 2*T-aa) - lower_bound(bb.begin(), bb.end(), T-aa);
            cnt += lower_bound(bb.begin(), bb.end(), 4*T-aa) - lower_bound(bb.begin(), bb.end(), 3*T-aa);
        }
        if(cnt%2==1) ans+=T;
    }
    cout << ans << endl;
}
