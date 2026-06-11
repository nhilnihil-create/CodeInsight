#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll N, M;
    cin >> N >> M;

    ll ans = 100 * (N - M) + 1900 * M;
    ll n = 1LL << M;
    
    ans *= n;

    cout << ans << endl;
    return 0;
}