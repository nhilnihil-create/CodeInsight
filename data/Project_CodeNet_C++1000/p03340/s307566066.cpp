#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define INF 10000000000
using namespace std;
using ll = long long;
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n){
        cin >> a[i];
    }
    int l = 0, r = 0;
    int now = 0;
    ll ans = 0;
    while(l<n){
        while(r < n && (now^a[r]) == now + a[r]){
            now ^= a[r++];
            ans++;
        }
        now ^= a[l++];
        ans += r - l;
    }
    cout << ans << endl;
}
