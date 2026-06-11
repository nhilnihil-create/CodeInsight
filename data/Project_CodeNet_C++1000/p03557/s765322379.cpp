#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T>
using vec = std::vector<T>;

int main() {
    int N;
    cin >> N;
    vec<ll> A(N),B(N),C(N);
    rep(i,N) cin >> A[i];
    rep(i,N) cin >> B[i];
    rep(i,N) cin >> C[i];
    sort(all(A));sort(all(B));sort(all(C));

    ll ans = 0;
    rep(i,N){
        ll b = B[i];
        ll a = lower_bound(all(A),b) - A.begin();
        ll c = upper_bound(all(C),b) - C.begin();
        ans+=a*(C.size()-c);
    }
    cout << ans << endl;
}