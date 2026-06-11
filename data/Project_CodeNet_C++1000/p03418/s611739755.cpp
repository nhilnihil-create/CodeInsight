#include <iostream>

using namespace std;
typedef long long ll;

ll f(ll x, ll b, ll K) {
    if (x % b <= K-1)
        return K * (x/b) + x%b + 1;
    else 
        return K *  (x/b + 1);
}

int main() {
    ll N, K, ans = 0, b;    cin >> N >> K;
    for (b = 1; b <= N; b++)
        ans += max((ll)0, b-K) * (N/b) + max((ll)0, N%b - K +1);
    cout << ans - ((K==0) ? N : 0) << endl;
    return 0;
}