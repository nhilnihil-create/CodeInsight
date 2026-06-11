#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll N;
    cin >> N;
    vector<ll> C(N), S(N), F(N);
    rep(i, 0, N-1) cin >> C[i] >> S[i] >> F[i];
    rep(i, 0, N){
        ll ans = 0;
        rep(j, i, N-1){
            if(ans < S[j]) ans = S[j];
            else if(ans % F[j] != 0) ans += F[j] - ans % F[j];
            ans += C[j];
        }
        cout << ans << endl;
    }
    return 0;
}