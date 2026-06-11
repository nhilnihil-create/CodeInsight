#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll N;
    cin >> N;
    vector<ll> h(N);
    rep(i, 0, N) cin >> h[i];
    ll ans = h[0];
    rep(i, 1, N){
      if(h[i] > h[i-1]) ans += h[i] - h[i-1];
    }
    cout << ans << endl;
    return 0;
}
