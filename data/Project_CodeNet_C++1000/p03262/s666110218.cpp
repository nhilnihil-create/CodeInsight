#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;
const ll INF = 1e16;

void solver(ll N, vector<ll> &x, ll &ans){

    if(N == 1) ans = abs(x.at(1)-x.at(0));
    else{
        sort(x.begin(), x.end());

        for(ll i = 0; i != N-1; ++i){
            ll left{}, right{};
            left = x.at(i+1) - x.at(i);
            right = x.at(i+2) - x.at(i+1);

            ll tmp{};
            tmp = __gcd(left, right);
            ans = min(ans, tmp);
        }
    }

    return;
}

int main(){

    ll N, X;
    cin >> N >> X;
    vector<ll> x;
    x.push_back(X);
    for(ll i = 0; i != N; ++i){
        ll tmp;
        cin >> tmp;
        x.push_back(tmp);
    }

    ll ans = INF;
    solver(N, x, ans);

    cout << ans << endl;
    return 0;
}
