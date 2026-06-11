#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int64_t i = 0; i < (int64_t)(n); i++)
using vi = vector<int64_t>;
using vvi = vector<vi>;
using ll = int64_t;
using P = pair<ll,ll>;
ll INF = 1000000007;
// ll INF = 9223372036854775807;
// ll INF = 998244353;

int main() {
    // fasten cin
    cin.tie(0);
    ios::sync_with_stdio(false);
    // implement
    ll n;
    cin >> n;
    vi a(n);
    rep(i,n) cin >> a.at(i);
    vi a2 = a;
    rep(i,n) a2.at(i) -= i+1;
    sort(a2.begin(), a2.end());
    ll res = 0;
    if(n%2==1){
        ll b = a2.at(n/2);
        rep(i,n) res += abs(a.at(i) - (b+i+1));
    }else{
        ll b1 = a2.at(n/2);
        ll res1 = 0;
        rep(i,n) res1 += abs(a.at(i) - (b1+i+1));
        ll b2 = a2.at(n/2-1);
        ll res2 = 0;
        rep(i,n) res2 += abs(a.at(i) - (b2+i+1));
        res = std::min(res1,res2);
    }
    cout << res << endl;
}