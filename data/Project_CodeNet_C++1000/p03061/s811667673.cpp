#include <bits/stdc++.h>
using namespace std;
#define Hello ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int main(){
    Hello
    ll n;
    cin >> n;
    ll arr[n + 5];
    for(int i = 0; i < n; i++) cin >> arr[i];
    ll l[n + 5] = {}, r[n + 5] = {}, ans = 0;
    for(int i = n - 1; i >= 0; i--) r[i] = __gcd(r[i + 1], arr[i]);
    for(int i = 0; i < n; i++) l[i + 1] = __gcd(l[i], arr[i]);
    for(int i = 0; i < n; i++)
        ans = max(ans, __gcd(l[i], r[i + 1]));
    cout << ans;
    return 0;
}
