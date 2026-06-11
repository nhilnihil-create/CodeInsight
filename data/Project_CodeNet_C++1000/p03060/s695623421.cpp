#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define rep(i,n); for(long long i = 0;i < (n);i++)
using ll = long long;
using P = pair<long long,long long>;
template <class T> using vec = vector<T>;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n; cin >> n;
    vec<ll> v(n),c(n); rep(i,n)cin >> v[i]; rep(i,n)cin >> c[i];
    ll ans = 0;
    rep(i,n){
        if(v[i] - c[i] > 0)ans += v[i] - c[i]; 
    }
    cout << ans << endl;
}