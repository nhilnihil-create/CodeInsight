#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int K;
    cin >> K;
    vector<ll> A(K);
    for (int i = 0; i < K; i++) cin >> A[i];
    ll l = 0;
    ll r = 1e15;
    while (r - l > 1) {
        ll c = (l+r)/2;
        ll d = c;
        for (int i = 0; i < K; i++) {
            d /= A[i];
            d *= A[i];
        }
        if (d < 2) l = c;
        else r = c;
    }
    ll s = r;
    
    l = 0;
    r = 1e15;
    while (r - l > 1) {
        ll c = (l+r)/2;
        ll d = c;
        for (int i = 0; i < K; i++) {
            d /= A[i];
            d *= A[i];
        }
        if (d < 3) l = c;
        else r = c;
    }
    ll t = r;
    if (s == t) cout << -1 << endl;
    else cout << s << " " << t-1 << endl;
    return 0;
}