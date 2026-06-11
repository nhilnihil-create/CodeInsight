#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll N, Z, W;
    cin >> N >> Z >> W;
    vector<ll> a(N);
    rep(i, 0, N) cin >> a[i];

    if(N == 1){
        cout << abs(W-a[0]) << endl;
        return 0;
    }
    ll ans = max(abs(W-a[N-1]), abs(a[N-2]-a[N-1]));
    cout << ans << endl;
    return 0;
}