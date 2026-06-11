#include <bits/stdc++.h>
using namespace std;

int main(){
    long N, K;
    cin >> N >> K;
    long x[N];
    for(int i = 0; i < N; i++) cin >> x[i];
    long ans = LONG_MAX;
    for(int i = 0; i + K <= N; i++){
        if(x[i + K - 1] <= 0) ans = min(ans, abs(x[i]));
        else if(x[i] <= 0) ans = min(ans, min(abs(x[i]), x[i + K - 1]) + x[i + K - 1] - x[i]);
        else ans = min(ans, x[i + K - 1]);
    }
    cout << ans << endl;
    return 0;
}