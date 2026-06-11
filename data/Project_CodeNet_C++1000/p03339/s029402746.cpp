#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define ve vector
#define chmin(x,y) x = min(x,y)

int main(){
    int n;
    string s;
    cin >> n >> s;
    ve<int> e(n+1),w(n+1);
    e[0] = 0;
    w[0] = 0;
    rep(i,n){
        if(s[i] == 'E')e[i+1]++;
        else w[i+1]++;
        e[i+1] += e[i];
        w[i+1] += w[i];
    }
    int ans = 2e9;
    rep(i,n){
        ans = min(ans,w[i]-w[0] + e[n]-e[i+1]);
    }
    cout << ans << endl;
    return 0;
}
