#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T>
using vec = std::vector<T>;

int main() {
    ll N,M;
    cin >> N >> M;
    vec<ll> A(N);
    rep(i, N) cin >> A[i];
    map<ll,ll> mp;
    
    mp[0] = 1;
    ll now = 0;
    ll ans = 0;
    rep(i,N){
        now = (now + A[i])%M;
        ans += mp[now];
        ++mp[now];
    }
    cout << ans << endl;
}