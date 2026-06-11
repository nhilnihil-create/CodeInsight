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
    ll a,b,k;
    cin >> a >> b >> k;
    rep(i,k/2){
        if(a%2==1) a -= 1;
        b += a/2;
        a /= 2;
        if(b%2==1) b -= 1;
        a += b/2;
        b /= 2;
    }
    if(k%2==1){
        if(a%2==1) a -= 1;
        b += a/2;
        a /= 2;
    }
    cout << a << " " << b << endl;
}