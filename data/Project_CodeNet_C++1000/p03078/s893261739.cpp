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

vector<ll> a, b, c;

int main(){
    ll x, y, z, k;
    cin >> x >> y >> z >> k;
    rep(i, x){
        ll A;
        cin >> A;
        a.push_back(A);
    }
    rep(i, y){
        ll B;
        cin >> B;
        b.push_back(B);
    }
    rep(i, z){
        ll C;
        cin >> C;
        c.push_back(C);
    }
    sort(c.begin(), c.end(), greater<ll>());
    vector<ll> ab;
    rep(i, x){
        rep(j, y) ab.push_back(a[i] + b[j]);
    }
    sort(ab.begin(), ab.end(), greater<ll>());
    
    vector<ll> ans;
    ll idx_ab = min(k, x * y);
    ll idx_c = min(k, z);

    rep(i, idx_ab) rep(j, idx_c) ans.push_back(ab[i] + c[j]);
    sort(ans.begin(), ans.end(), greater<ll>());

    rep(i, k) cout << ans[i] << endl;

    return 0;
}