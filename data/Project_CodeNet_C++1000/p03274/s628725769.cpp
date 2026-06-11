#include<bits/stdc++.h>
#define forr(i, a, b) for(int i = (a); i < (b); i++)
#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = 1; i <= (n); i++)
#define ALL(a) (a.begin()),(a.end())
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll, ll> LP;
const ll LINF = 1LL<<60;
const int INF = 1001001001;
const int MOD = 1000000007;

/* --------------------------------------------------- */

int main() {
    int n, k;
    cin >> n >> k;
    vector<ll> x(n);
    rep(i, n) cin >> x[i];
    ll ans = LINF;
    rep(i, n - k + 1) {
        int l = i, r = i + k - 1;
        ll tot;
        if(x[r] < 0) tot = abs(x[l]);
        else if(x[l] > 0) tot = x[r];
        else tot = min(abs(x[l]) * 2 + x[r], abs(x[l]) + x[r] * 2);

        ans = min(ans, tot);
    }

    cout << ans << endl;

    return 0;
}