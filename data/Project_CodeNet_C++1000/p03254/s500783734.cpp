#include <bits/stdc++.h>
#define rep(i, a, n) for(int i = a; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n, x;
    cin >> n >> x;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];
    sort(a.begin(), a.end());
    ll res = 0;
    rep(i, 0, n){
        res += a[i];
    }
    if(res == x){
        cout << n << endl;
        return 0;
    }
    int ans = 0;
    ll sum = 0;
    rep(i, 0, n-1){
        sum += a[i];
        if(sum > x) break;
        ans++;
    }
    cout << ans << endl;
    return 0;
}
