#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = b - 1; i >= a; i--)
typedef long long ll;


int main(){
    ll K; cin >> K;
    vector<ll> A(K);
    rep(i, 0, K) cin >> A[i];

    ll ub = 1e18, lb = 1;
    
    // 最小の値
    while(ub - lb > 1){
        ll m = (ub + lb) / 2;
        ll tmp = m;
        rep(i, 0, K){
            tmp = tmp - tmp % A[i];
        }
        if(tmp < 2) lb = m;
        else ub = m;
    }
    ll ans_s = ub;
    ub = 1e18, lb = 2;
    while(ub - lb > 1){
        ll m = (ub + lb) / 2;
        ll tmp = m;
        rep(i, 0, K){
            tmp = tmp - tmp % A[i];
        }
        if(tmp > 2) ub = m;
        else lb = m;
    }
    ll ans_b = lb;

    if(ans_b < ans_s){
        cout << -1 << endl;
        return 0;
    }
    /* ll tmp = ans_s;
    rep(i, 0, K){
        tmp = tmp - tmp % A[i];
    }
    if(tmp != 2){
        cout << -1 << endl;
        return 0;
    } */
    cout << ans_s << " " << ans_b << endl;
}