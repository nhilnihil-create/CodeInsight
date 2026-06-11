#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(ll i = 0; i < (ll) n; i++)
#define xrep(i,x,n) for(ll i = (ll) x; i < (ll) n; i++)
#define vl vector<long long>
#define vs vector<string>

int main() {
    ll N, K; cin >> N >> K;
    vl h(N);
    rep(i,N) cin >> h[i];

    sort(h.begin(),h.end());

    vl a(N-K+1);
    rep(i,N-K+1) a[i] = h[K - 1 + i] - h[i];

    sort(a.begin(),a.end());

    cout << a[0] << endl;
}