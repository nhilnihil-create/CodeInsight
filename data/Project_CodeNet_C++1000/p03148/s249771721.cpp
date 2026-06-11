#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;
const int MOD = 1000000007;
const int MOD2 = 998244353;


//ref : https://atcoder.jp/contests/abc116/submissions/4327163

int main(){
    ll n, k;
    cin >> n >> k;
    vector<P> sushi(n);
    rep(i, n){
        ll t, d;
        cin >> t >> d;
        t--;
        sushi[i] = {d, t};
    }
    sort(sushi.begin(), sushi.end());
    reverse(sushi.begin(), sushi.end());

    ll ans = 0;
    vector<ll> used(n,0);
    stack<ll> sta;
    ll res = 0;
    ll kind = 0;
    rep(i, k){
        res += sushi[i].first;
        if(used[sushi[i].second]++==0) kind++;
        else sta.push(sushi[i].first);
    }
    ans = res + kind * kind;
    for(int i = k; i < n && sta.size(); i++){
        if(used[sushi[i].second]++)continue;
        ll a = sta.top();
        sta.pop();
        res -= a;
        res += sushi[i].first;
        kind++;
        ans = max(ans, res + kind * kind);
    }
    cout << ans << endl;

    return 0;
}
