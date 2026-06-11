#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define chmin(a,b) a = min(a,b)
#define chmax(a,b) a = max(a,b)
#define all(a) a.begin(), a.end()
using namespace std;
using ll = long long;
using vi = vector<int>;
using vv = vector<vi>;

int main(){
    int n; cin >> n;
    vi a(n), b(n), c(n);
    
    rep(i,n)cin>>a[i];
    rep(i,n)cin>>b[i];
    rep(i,n)cin>>c[i];
    
    sort(all(a));
    sort(all(b));
    sort(all(c));
    
    ll ans = 0;
    
    
    rep(i,n){
        ll na = lower_bound(all(a), b[i]) - a.begin();
        ll nc = c.end() - upper_bound(all(c), b[i]);
        ans  += na * nc;
    }
    
    cout << ans << endl;
    
    return 0;
}