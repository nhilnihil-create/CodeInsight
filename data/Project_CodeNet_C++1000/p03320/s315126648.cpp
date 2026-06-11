#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

bool cmp(pll u, pll v){
    return u.va * v.vb == v.va * u.vb ?
                          u.va < v.va :
            u.va * v.vb < v.va * u.vb ;
}
ll S(ll n){
    ll ans = 0;
    for(;n;n/=10LL){
        ans += n % 10;
    }
    return ans;
}
ll f(ll N){
    vector<pll> V({pll(N, S(N))});
    for(ll ten = 10; 10LL * N >= ten; ten *= 10LL){
        ll X = N / ten * ten + ten - 1LL;
        V.emplace_back(X, S(X));
    }
    sort(V.begin(), V.end(), cmp);
    /*
    for(pll &p : V){
        cout << p.va << ' ' << p.vb << '\n';
    }
    cout << '\n';
    */
    return V[0].va;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int K;
    cin >> K;
    ll s = 1;
    for(int i = 0; i < K; i++){
        cout << s << '\n';
        s = f(s+1LL);
    }
}
