#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll N;
    string S;
    cin >> N >> S;
    vector<ll> b(N, 0), w(N, 0);
    rep(i, 1, N){
        b[i] = b[i-1];
        if(S[i-1] == '#') b[i]++;
    }
    for(ll i = N-2; i >= 0; i--){
        w[i] = w[i+1];
        if(S[i+1] == '.') w[i]++;
    }
    ll ans = 1e18;
    rep(i, 0, N) ans = min(ans, b[i] + w[i]);
    cout << ans << endl;
    return 0;
}