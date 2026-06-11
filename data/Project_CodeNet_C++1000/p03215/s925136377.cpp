#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < n; i++)

typedef long long ll;
using namespace std;
int mod = 1000000007;

int main(void){
    int N, M; cin >> N >> M;
    vector<ll> S;
    ll A[N]; rep(i, N) cin >> A[i];
    ll ruiseki[N+1]; ruiseki[0] = 0; rep(i, N) ruiseki[i+1] = ruiseki[i] + A[i];
    for(int i = 0; i < N; i++){
        for(int j = i+1; j <= N; j++){
            S.push_back(ruiseki[j]-ruiseki[i]);
        }
    }
    int bit_cnt = 0;
    ll ans = 0;
    rep(i, 41){
        bit_cnt = 0;
        ll val = (1ll << (40-i));
        rep(j, S.size()){
            if((val & S[j]) == val) bit_cnt++;
        }
        if(bit_cnt >= M){
            ans += val;
            rep(j, S.size()){
                if((val & S[j]) != val) S[j] = 0;
            }
        }
    }
    cout << ans << endl;
    return 0;
}