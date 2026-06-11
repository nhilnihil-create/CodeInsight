#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;

int main() {
    int n;
    cin >> n;
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    ll m = 0, a = 0, r = 0, c = 0, h = 0;
    rep(i,n) {
        if(s[i][0]=='M') ++m;
        if(s[i][0]=='A') ++a;
        if(s[i][0]=='R') ++r;
        if(s[i][0]=='C') ++c;
        if(s[i][0]=='H') ++h;
    }
    ll ans = 0;
    vector<ll> name(5);
    name[0] = m, name[1] = a, name[2] = r, name[3] = c, name[4] = h;
    rep(i,5){
        for(int j = i+1; j < 5; ++j){
            for(int k = j+1; k < 5; ++k){
                ans+=name[i]*name[j]*name[k];
            }
        }
    }
    cout << ans << endl;
    return 0;
}