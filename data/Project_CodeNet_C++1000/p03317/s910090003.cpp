#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define ve vector
#define chmin(x,y) x = min(x,y)

int main(){
    int n,k;
    cin >> n >> k;
    int ans = 1;
    n -= k;
    k--;
    ans += (n+k-1)/k;
    cout << ans << endl;
    return 0;
}
