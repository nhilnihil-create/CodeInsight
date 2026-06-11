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
    if(n<105){
        cout << 0 << endl;
        return 0;
    }
    ll res = 0;
    for(ll i=105;i<=n;i+=2){
        ll temp = 0;
        for(ll j=1;j<=i;j+=2){
            if(i%j==0) temp++;
        }
        if(temp==8) res++;
    }
    cout << res << endl;
}