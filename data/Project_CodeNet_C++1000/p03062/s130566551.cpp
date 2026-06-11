#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n); 
    rep(i,n) cin >> a[i];
    ll mn = 99999999999;
    int cnt = 0;
    ll ans = 0;
    rep(i,n){
        if(a[i]<0) cnt++;
        mn = min(mn,abs(a[i]));
        ans+=abs(a[i]);
    }
    if(cnt%2) cout << ans-mn*2 << endl;
    else cout << ans << endl;
    return 0;
}