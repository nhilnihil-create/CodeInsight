#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0; i<n; i++)
#define eb(t) emplace_back(t)
typedef long long ll;
typedef long long unsigned int llu;
ll INF = 1000000009;
ll MOD = 1000000007;


void solve(){

    ll k;
    cin >> k;
    ll a[100010];
    rep(i,k){
        cin >> a[i];
    }
    ll l=2;
    ll r=2;
    for(ll i=k-1; i>=0; i--){
        if(r<a[i]) {
            cout << -1 << endl;
            return;
        }
        if(l/a[i]==r/a[i]&&0<(l%a[i])&&0<(r%a[i])){
            cout << -1 << endl;
            return;
        }

        l = ((l+a[i]-1)/a[i])*a[i];
        r = (r/a[i])*a[i] + a[i]-1;
    }
    cout << l << " " << r << endl;

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
