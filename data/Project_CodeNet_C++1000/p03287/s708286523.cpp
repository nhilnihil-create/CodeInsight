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

ll a[100010];
ll b[100010];
int main(){
    int n, m;
    cin >> n >> m;
    rep(i, n) cin >> a[i];
    ll tmp = 0;
    rep(i, n){
        tmp += a[i];
        b[i+1] = tmp;
    }
    map<ll, ll> mp;

    rep(i, n+1){
        mp[b[i]%m]++;
    }
    ll ans = 0;
    for(auto v : mp){
        ll num = v.second;
        ans += num * (num - 1) / 2;
    }
    cout << ans << endl;

    return 0;
}