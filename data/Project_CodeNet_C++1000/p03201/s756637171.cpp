#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int N = 2e5+5;
int n, a[N];
unordered_map<ll,int> mp;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a+n);
    int ans = 0;
    ll pw = 1ll<<40;
    for(int i = n - 1; i >= 0; i--) {
        if(mp[a[i]]) {
            ans++;
            mp[a[i]]--;
            continue;
        }
        while(pw/2>a[i]) pw/=2;
        mp[pw-a[i]]++;
    }
    cout << ans;
    return 0;
}