#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int N;
    cin >> N;
    vector<ll> A(N), B(N), C(N);
    
    rep(j, N) cin >> A.at(j);
    rep(j, N) cin >> B.at(j);
    rep(j, N) cin >> C.at(j);
    
    sort(A.begin(), A.end());
    sort(C.begin(), C.end());

    ll ans = 0;
    rep(j, N) {
        ll i = lower_bound(A.begin(), A.end(), B.at(j)) - A.begin();
        ll k = C.end() - upper_bound(C.begin(), C.end(), B.at(j));
        ans += i * k;
    }
    cout << ans << endl;
}
