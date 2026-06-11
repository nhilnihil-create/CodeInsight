#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define ve vector
#define chmin(x,y) x = min(x,y)

int main(){
    string s;
    ll k;
    cin >> s >> k;
    k--;
    int n = (int)s.size();
    int n1 = n-1;
    char c = '1';
    rep(i,n){
        if(s[i] == '1') continue;
        else{
            c = s[i];
            n1 = (int)i-1;
            break;
        }
    }
    if(k <= n1) cout << 1 << endl;
    else cout << c << endl;
    return 0;
}
