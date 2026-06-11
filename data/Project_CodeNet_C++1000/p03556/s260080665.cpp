#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;

int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    ll N;
    cin >> N;

    ll ans;

    for(ll i = 1; i * i <= N; i++) {
        ans = i;
    }

    cout << ans * ans << endl;
}