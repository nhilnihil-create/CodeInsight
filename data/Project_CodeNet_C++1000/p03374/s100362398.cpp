#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int N; ll C;
    cin >> N >> C;
    vector<ll> x(N+1,0), v(N+1,0);
    for(int i=1; i<=N; i++) cin >> x[i] >> v[i];

    vector<ll> calc(N+1,0), cala(N+1,0);
    for(int i=1; i<=N; i++){
        calc[i] = calc[i-1] + v[i] - (x[i] - x[i-1]);
    }
    cala[N] = v[N] - (C - x[N]);
    for(int i=N-1; i>=1; i--){
        cala[i] = cala[i+1] + v[i] - (x[i+1] - x[i]);
    }

    vector<ll> calcM(N+1), calaM(N+1);
    for(int i=1; i<=N; i++) calcM[i] = max(calcM[i-1], calc[i]);
    calaM[N] = max((ll)0, cala[N]);
    for(int i=N-1; i>=1; i--) calaM[i] = max(calaM[i+1], cala[i]);

    ll ans = 0;
    for(int i=1; i<=N; i++){
        ans = max(ans, calc[i]);
        ans = max(ans, cala[i]);
    }

    for(int i=1; i<N; i++){
        ans = max(ans, calc[i] - x[i] + calaM[i+1]);
    }
    for(int i=N; i>1; i--){
        ans = max(ans, cala[i] - (C - x[i]) + calcM[i-1]);
    }
    cout << ans << endl;
}
