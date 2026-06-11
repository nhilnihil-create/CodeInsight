#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    int N, K; cin >> N >> K;
    vector<ll> x(N);
    vector<ll> y(N);
    rep(i, N){
        cin >> x[i] >> y[i];
    }

    ll ans = (1e18) * 5;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            for (int k = 0; k < N; k++){
                for (int l = 0; l < N; l++){
                    if(x[i] <= x[j] && y[k] <= y[l]){
                        int cnt = 0;
                        for (int m = 0; m < N; m++){
                            if(x[m] >= x[i] && x[m] <= x[j] && y[m] >= y[k] && y[m] <= y[l]){
                                cnt++;
                            }
                        }
                        if(cnt >= K){
                            ans = min(ans, (x[j] - x[i]) * (y[l] - y[k]));
                        }
                    }
                }
            }
        }
    }
    
    cout << ans << endl;

    return 0;
}