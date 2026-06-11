#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int64_t i = 0; i < (int64_t)(n); i++)
using vi = vector<int64_t>;
using vvi = vector<vi>;
using ll = long long ;
using P = pair<ll,ll>;
ll INF = 1000000007;
// ll INF = 9223372036854775807;
// ll INF = 998244353;

int main() {
    // fasten cin
    cin.tie(0);
    ios::sync_with_stdio(false);
    // implement
    ll n,k;
    cin >> n >> k;
    vi v(n);
    rep(i,n) cin >> v.at(i);
    ll num = min(n,k);
    vi vals;
    rep(i,num+1){
        rep(j,num+1-i){
            ll val = 0;
            vi items;
            ll rest = k-i-j;
            rep(t,i) items.push_back(v.at(t));
            rep(t,j) items.push_back(v.at(n-1-t));
            sort(items.begin(), items.end());
            rep(l,items.size()) val += items.at(l);
            rep(l,rest){
                if(l>=items.size()) break;
                if(items.at(l)<0) val -= items.at(l);
            }
            vals.push_back(val);
            cerr << "i:" << i << " j:" << j << " val:" << val << endl;
        }
    }
    sort(vals.begin(), vals.end(), greater<>());
    cout << vals.at(0) << endl;
}