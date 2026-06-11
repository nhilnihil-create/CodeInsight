#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
    int N; cin >> N;
    vector<int> A(N), B(N), C(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) cin >> B[i];
    for (int i = 0; i < N; i++) cin >> C[i];
    sort(A.begin(), A.end());
    sort(C.begin(), C.end());

    ll ans = 0;
    for (int i = 0; i < N; i++) {
        ll cnt1 = lower_bound(A.begin(), A.end(), B[i]) - A.begin();
        ll cnt2 = C.end() - upper_bound(C.begin(), C.end(), B[i]);
        ans += cnt1 * cnt2;
    }
    cout << ans << endl;
}