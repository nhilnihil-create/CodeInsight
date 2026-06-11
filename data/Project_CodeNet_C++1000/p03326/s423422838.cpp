#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll n, m;
    cin >> n >> m;
    vector<ll> x(n), y(n), z(n);
    rep(i, 0, n) cin >> x[i] >> y[i] >> z[i];
    ll ans = 0;
    for(int i = 0; i < 8; i++){
        ll c[3] = {1, 1, 1};
        for(int j = 0; j < 3; j++){
            if(i & (1<<j)) c[j] = -1;
        }
        ll tmp = 0;
        vector<ll> t;
        rep(j, 0, n) t.push_back(c[0] * x[j] + c[1] * y[j] + c[2] * z[j]);
        sort(t.begin(), t.end(), greater<ll>());
        rep(j, 0, m) tmp += t[j];
        ans = max(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}