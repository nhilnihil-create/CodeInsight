#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int main() {
    ll n, m; cin >> n >> m;
    if(n > m) swap(n, m);
    ll ans = 0;
    if(n==1&&m==1) ans = 1;
    else if(n==1&&m>=2) ans = m - 2;
    else ans = (n-2) * (m-2);
    cout << ans;
}
