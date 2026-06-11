#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1000000007;

int main() {
    ll N;
    cin >> N;
    vector<ll>a(N);
    ll total = 0;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        a[i] = a[i]-(i+1);
        total += a[i];
    }
    
    sort(a.begin(), a.end());
    int num = a[N/2];
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        ans += abs(a[i]-num);
    }
    cout << ans << endl;
}
