#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define PB push_back
#define MP make_pair

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ll a; cin >> a; ans += a - 1;
    }
    cout << ans << "\n";
}