#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define ve vector

int main(){
    int n,k;
    cin >> n >> k;
    ve<int> h(n);
    rep(i,n) cin >> h[i];
    sort(h.begin(), h.end());
    int ans = h[k-1] - h[0];
    int i = k;
    while(i < n){
        ans = min(ans,h[i] - h[i-k+1]);
        i++;
    }
    cout << ans << endl;
    return 0;
}
