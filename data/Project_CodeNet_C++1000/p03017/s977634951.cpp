#include <bits/stdc++.h>
#define rep(i, n) for(ll i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const double PI=acos(-1);

int main(){
    ll n, a, b, c, d;
    string s;
    cin >> n >> a >> b >> c >> d >> s;
    vector<ll> space;
    ll cnt = 0;
    bool exchange = false;
    for(ll i = min(a-1, b-1); i < max(c, d); ++i){
        if(i != n-1 && s[i] == '#' && s[i+1] == '#'){
            cout << "No" << endl;
            return 0;
        }
        if(i >= b-2 && i <= d && s[i] == '.') cnt++;
        if(s[i] == '#') cnt = 0;
        if(cnt >= 3) exchange = true;
    }
    if(c < d) cout << "Yes" << endl;
    else{
        if(!exchange) cout << "No" << endl;
        else cout << "Yes" << endl;
    }
    return 0;
}