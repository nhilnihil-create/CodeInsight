#include<bits/stdc++.h>

using namespace std;
using ll = long long;


int main()
{
    int n, k; cin >> n >> k;
    ll ans = 0;

    for(int b = k + 1; b <= n; b++) {
        ll cur = n / b * (b - k);
        cur += max((n % b) - max(0,(k - 1)) , 0);
        ans += cur;
    }
    cout << ans << endl;
}