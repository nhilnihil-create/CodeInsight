#include<bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (int)(n); i++)
#define put(i) cout<<fixed<<i<<endl
using namespace std;
using ll = long long;

int main(){
    ll n, m; cin >> n >> m;
    ll ans = 0;
    vector<ll> x(m), l(m-1);
    rep(i,m) cin >> x[i];

    sort(x.begin(), x.end());

    for(long long i = 0; i < m-1; i++){
        l[i] = x[i+1] - x[i];
    }

    sort(l.begin(), l.end(), greater<ll>());

    for(long long i = n-1; i < m; i++) ans += l[i];

    put(ans);
}