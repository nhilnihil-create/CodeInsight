#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i ++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;
const ll MOD = 1e9 + 7;
const ll INF = 1e10;

int main() {
    int n,z,w; cin >> n >> z >> w;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    int ans;
    if (n == 1) ans = abs(w - a[n - 1]);
    else ans = max(abs(w - a[n - 1]),abs(a[n - 1] - a[n - 2]));
    cout << ans << endl;
}