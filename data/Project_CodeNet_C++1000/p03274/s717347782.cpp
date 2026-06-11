#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
using Graph = vector<vector<int>>;
#define MOD 1000000007
#define MOD2 998244353
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;

int main(){
    int n, k;
    cin >> n >> k;
    ll x[n];
    rep(i, n) cin >> x[i];
    ll ans = LINF;
    rep(i, n - k + 1){
        ll mn = x[i];
        ll mx = x[i + k - 1];
        ll tmp = min(abs(mn), abs(mx)) + abs(mx - mn);
        ans = min(ans , tmp);
    }

    cout << ans << endl;

    return 0;
}