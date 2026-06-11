#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T>
using vec = std::vector<T>;

int main() {
    int N;
    cin >> N;
    vec<ll> A(N);
    rep(i, N) cin >> A[i];
    map<ll,int> mp;
    ll now = 0;
    ll ans = 0;
    mp[0] = 1;
    rep(i,N){
        now+=A[i];
        ans += mp[now];
        ++mp[now];
    }
    cout << ans << endl;
}
