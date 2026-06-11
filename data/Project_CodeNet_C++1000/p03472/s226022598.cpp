#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;

int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, H;
    cin >> N >> H;

    vector<ll> a(N);
    vector<ll> b(N);

    for(int i = 0; i < N; i++) {
        cin >> a[i] >> b[i];
    }

    ll am = *max_element(a.begin(), a.end());

    sort(b.begin(), b.end(), greater<ll>());

    ll ans = 0;

    for(int i = 0; i < N; i++) {
        if(b[i] <= am) break;
        H -= b[i];
        ans++;
        if(H <= 0) {
            cout << ans << endl;
            return 0;
        }
    }

    if(H % am == 0) {
        ans += H / am;
    } else {
        ans += H / am + 1LL;
    }

    cout << ans << endl;
}