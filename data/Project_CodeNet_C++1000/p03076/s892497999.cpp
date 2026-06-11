#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;

int main() {
    vector<int> a(5);
    rep(i,5) cin >> a[i];
    ll ans = 999999999;
    do{
        ll t = 0;
        rep(i,5){
            t = (t+9)/10*10;
            t+=a[i];
        }
        ans = min(ans, t);

    }while(next_permutation(all(a)));
    
    cout << ans << endl;
    return 0;
}