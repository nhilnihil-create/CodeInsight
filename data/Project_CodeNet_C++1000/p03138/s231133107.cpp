#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T>
using vec = std::vector<T>;

int main() {
    ll N,K;
    cin >> N >> K;
    vec<ll> A(N);
    rep(i, N) cin >> A[i];
    
    int first1 = 0;
    rep(i,60) if((K>>i)&1) first1=i;
    ll msk = 0;
    ll msk2 = 0;
    for(int i=40;i>=0;--i){
        ll cnt = 0;
        rep(j,N) if((A[j]>>i)&1) ++cnt;
        if(cnt*2<=N && msk+(1LL<<i)<=K) msk^=(1LL<<i);
        if(cnt*2<=N && i<first1) msk2^=(1LL<<i);
    }
    
    ll ans = 0;
    ll ans2 = 0;
    rep(i,N){
        ans += (A[i]^msk);
        ans2 += (A[i]^msk2);
    }
    cout << max(ans,ans2) << endl;
}