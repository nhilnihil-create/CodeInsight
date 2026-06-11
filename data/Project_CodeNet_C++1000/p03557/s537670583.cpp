#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;

int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    ll N;
    cin >> N;
    
    vector<ll> A(N);
    vector<ll> B(N);
    vector<ll> C(N);

    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < N; i++) cin >> B[i];
    for(int i = 0; i < N; i++) cin >> C[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sort(C.begin(), C.end());

    vector<ll> bc(N);

    for(int i = 0; i < N; i++) {
        ll x = upper_bound(C.begin(), C.end(), B[i]) - C.begin();
        bc[i] = N - x;
    }

    for(int i = N - 2; i >= 0; i--) {
        bc[i] += bc[i + 1];
    }

    ll ans = 0;

    for(int i = 0; i < N; i++) {
        ll x = upper_bound(B.begin(), B.end(), A[i]) - B.begin();
        ans += bc[x];
    }

    cout << ans << endl;
}