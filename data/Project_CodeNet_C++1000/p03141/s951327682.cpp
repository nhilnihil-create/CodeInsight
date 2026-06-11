#include <bits/stdc++.h>
#define loop2(i, s, n, a) for (int i = int(s); i < int(n); i += a)
#define loop(i, s, n) loop2(i, s, n, 1)
#define rep(i, n) loop(i, 0, n)

#define pb push_back
#define all(in) in.begin(),in.end()

using ll = long long;
using ull = unsigned long long;
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> a(n), b(n), c(n);
    rep(i,n){
        cin >> a[i] >> b[i];
        c[i] = a[i] + b[i];
    }
    sort(c.begin(),c.end());

    ll ans = 0;
    rep(i,n) ans -= (ll)b[i];
    for(int i = n-1; i >= 0; i -= 2)  ans += (ll)c[i];

    cout << ans << endl;
}