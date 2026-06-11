#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n) for(int i=0;i<(int)n;i++)
#define PI acos(-1)
#define fast_io ios_base::sync_with_stdio(false) ; cin.tie(0); cout.tie(0);
ll mod=1e9+7;

int main(){
    fast_io

    int n;
    cin >> n;
    vector<ll> A(n), B(n), C(n);
    rep(i,n) cin >> A[i];
    rep(i,n) cin >> B[i];
    rep(i,n) cin >> C[i];
    sort(A.begin(), A.end());
    // sort(B.begin(), B.end());
    sort(C.begin(), C.end());
    ll ans = 0;
    rep(i,n){
        ll num = B[i];
        auto iter_a = upper_bound(A.begin(), A.end(), num-1);
        auto iter_c = lower_bound(C.begin(), C.end(), num+1);
        ans += (iter_a - A.begin()) * (C.end() - iter_c);
    }
    cout << ans << endl;

    return 0;
}
