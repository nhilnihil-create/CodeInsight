#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < n; i++)

using namespace std;
using ll = long long;
int mod = 1000000007;

void solve();

int main(void){
    int N, K; cin >> N >> K;
    ll A[N]; rep(i, N) cin >> A[i];
    vector<ll> bt(N*(N+1)/2);
    int idx = 0;
    for(int i = 0; i < N; i++){
        ll acc = 0;
        for(int j = i; j < N; j++){
            acc += A[j];
            bt[idx] = acc;
            idx++;
        }
    }
    //rep(i, bt.size()) cout << bt[i] << " "; cout << endl;

    ll pow2[40]; pow2[0] = 1;
    for(int i = 1; i < 40; i++) pow2[i] = pow2[i-1] << 1;
    int m = 39; ll ans = 0;
    for(int t = m; t >= 0; t--){
        int cnt = 0;
        for(int i = 0; i < bt.size(); i++){
            if(((ans + pow2[t]) & bt[i]) == (ans + pow2[t])) cnt++;
        }
        if(cnt >= K) ans += pow2[t];
    }
    cout << ans << endl;
    return 0;
}

void solve(){}