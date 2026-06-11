#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#define abdelrahman010 ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;
using namespace std;
const int N = 1e5 + 5;
int n , a[N] , pref[N] , suf[N];
int main() {
    abdelrahman010
    cin >> n;
    for(int i = 1;i <= n;i++)
        cin >> a[i];
    for(int i = 1;i <= n;i++)
        pref[i] = __gcd(pref[i - 1] , a[i]);
    for(int i = n;i >= 1;i--)
        suf[i] = __gcd(suf[i + 1] , a[i]);
    int ans = 0;
    for(int i = 1;i <= n;i++)
        ans = max(ans , __gcd(pref[i - 1] , suf[i + 1]));
    cout << ans;
    return 0;
}