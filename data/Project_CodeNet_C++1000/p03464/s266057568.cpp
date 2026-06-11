#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < n; i++)

using namespace std;
using ll = long long;
int mod = 1000000007;

void solve();

int main(void){
    int K; cin >> K;
    ll A[K]; rep(i, K) cin >> A[i];
    ll ulim = 2, dlim = 2; //この時点でA[K-1]=2を仮定しているのでそうじゃないものを弾く必要がある
    for(int i = K-1; i >= 1; i--){
        ulim = (ulim - (ulim % A[i])) + A[i] - 1;
        ulim -= (ulim % A[i-1]);
        if(dlim % A[i-1] > 0){
            dlim += (A[i-1] - dlim % A[i-1]);
        }
        if(ulim == 0){
            cout << -1 << endl;
            return 0;
        }
    }
    //存在するならばulim+A[0]-1, dlimは正しい答え
    ll s0 = ulim+A[0]-1;
    ll s1 = dlim;
    //cout << s0 << " " << s1 << endl;
    rep(i, K){
        if(s0 % A[i] > 0) s0 -= s0 % A[i];
        if(s1 % A[i] > 0) s1 -= s1 % A[i];
    }
    if(s0 == 2 && s1 == 2) cout << dlim << " " << ulim+A[0]-1 << endl;
    else cout << -1 << endl;
    return 0;
}

void solve(){}