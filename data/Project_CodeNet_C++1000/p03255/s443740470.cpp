#include<bits/stdc++.h>
using namespace std;
using ull = uint64_t;

ull ceil(ull a, ull b){
    return a / b + !!(a % b);
}

int main(){
    ull N, X;
    cin >> N >> X;
    ull x[N];
    for(ull i = 0; i < N; i++) cin >> x[i];
    ull sum[N + 1] = {};
    ull ans = UINT64_MAX;
    for(ull i = 0; i < N; i++) sum[i + 1] = sum[i] + x[i];
    for(ull cnt = 1; cnt <= N; cnt++){
        ull side = N;
        ull tmp = sum[N] - sum[N - cnt] + N * X + cnt * X;
        for(ull i = 1; side; i++){
            ull mv = min(side, cnt);
            tmp += ((sum[side] - sum[side - mv]) - (sum[side - mv] - sum[side < mv + mv ? 0 : side - mv - mv])) * (i + 1) * (i + 1);
            side -= mv;
        }
        ans = min(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}
