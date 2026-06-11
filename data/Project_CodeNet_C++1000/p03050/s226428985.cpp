#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ll N; cin >> N;
    ll ans = 0;
    ll i = 1;
    while (i * i < N - i) {
        if ((N - i) % i == 0) ans += (N - i) / i;
        i++;
    }
    cout << ans << endl;
}
