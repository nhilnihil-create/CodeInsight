#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)


ll K;
vector<ll> A;

int main(){
    cin >> K;
    A.resize(K);
    rep(i, 0, K) cin >> A[i];

    if(A[K-1] != 2){
        cout << -1 << endl;
        return 0;
    }

    // min
    ll mn = 2, mx = 2;
    for(ll i = K-1; i >= 0; i--){
        
        ll tmn, tmx;
        
        if(mn % A[i] != 0 && mn + A[i] - mn % A[i] > mx){
            cout << -1 << endl;
            return 0;
        }

        tmn = (ll)((mn+A[i]-1)/A[i])*A[i];
        tmx = (ll)(mx/A[i])*A[i]+A[i]-1;

        mn = tmn; mx = tmx;
    }

    cout << mn << " " << mx << endl;
    return 0;
}