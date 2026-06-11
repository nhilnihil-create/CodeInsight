#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define ve vector

int main(){
    int n,q;
    cin >> n >> q;
    string s;
    cin >> s;
    s = 'Z' + s;
    ve<int> ruiseki(n+1);
    ruiseki[0] = 0;
    ruiseki[1] = 0;
    rep(i,n){
        ruiseki[i+1] = ruiseki[i];
        if(s[i] == 'A' && s[i+1] == 'C') ruiseki[i+1]++;
    }
    rep(Q,q){
        int l,r;
        cin >> l >> r;
        int ans = ruiseki[r] - ruiseki[l];
        cout << ans << endl;
    }
    return 0;
}