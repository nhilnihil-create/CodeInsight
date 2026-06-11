#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    ll a, b, memo;
    cin >> a >> b;
    b++;
    vector<ll> n(42);
    vector<ll> an(42);
    vector<ll> bn(42);
    rep(i, 42){
        n.at(i) = 0;
        an.at(i) = 0;
        bn.at(i) = 0;
    }
    rep(i, 42){
        memo = pow(2, i);
        an.at(i) = a/(memo*2)*memo + max(a%(memo*2)-memo, 0LL);
        bn.at(i) = b/(memo*2)*memo + max(b%(memo*2)-memo, 0LL);
        if((bn.at(i) - an.at(i))%2 == 1) n.at(i) = 1;
    }
    ll ans = 0;
    rep(i, 42){
        if(n.at(i) == 1) ans += pow(2, i);
    }
    cout << ans << endl;
    return 0;
}