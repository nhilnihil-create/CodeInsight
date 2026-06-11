#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> Pii;

int main() {
    int N; cin >> N;
    vector<ll> AB(N);
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        ll a, b; cin >> a >> b;
        ans -= b;
        AB[i] = a + b;
    }
    sort(AB.begin(), AB.end(), greater<ll>());
    for (int i = 0; i < N; i+=2) {
        ans += AB[i];
    }
    cout << ans << endl;
}