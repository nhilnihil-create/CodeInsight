#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
    ll tmp, K;
    vector<ll> A(3);
    rep(i,3) cin >> A[i];
    cin >> K;

    sort(A.begin(), A.end(), greater<ll>());
    ll ans = A[0];
    rep(i,K) ans *= 2;
    ans += A[1] + A[2];
    cout << ans << endl;
} 
