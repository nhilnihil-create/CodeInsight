#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <random>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define repp(i,n,m) for (int i = m; i < (n); ++i)
#define repl(i,n) for (long long i = 0; i < (n); ++i)
#define reppl(i,n,m) for (long long i = m; i < (n); ++i)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;
using PL = pair<long long, long long>;
using Pxy = pair<double, double>;
using T = tuple<int, int, bool>;
const int INF = 1001001007;
const int mod = 1000000007;
const int MOD = 998244353;
const ll inf = 1e18;
template <typename AT>
void printvec(vector<AT> &ar){
    rep(i,ar.size()-1) cout << ar[i] << " ";
    cout << ar[ar.size()-1] << endl;
}
template <typename Q>
void printvvec(vector<vector<Q>> &ar){
    rep(i,ar.size()){
        rep(j,ar[0].size()-1) cout << ar[i][j] << " ";
        cout << ar[i][ar[0].size()-1] << endl;
    }
}
template <typename S>
bool range(S a, S b, S x){
    return (a <= x && x < b);
}

int main() {
    ll a, b; cin >> a >> b;
    b++;
    vector<ll> aa(40,0);
    vector<ll> ab(40,0);
    ll c = 1LL;
    rep(i,40){
        ll da = a / (c*2LL);
        ll ma = a % (c*2LL);
        aa[i] = c * da + max(0LL,ma-c);
        ll db = b / (c*2LL);
        ll mb = b % (c*2LL);
        ab[i] = c * db + max(0LL,mb-c);
        c *= 2LL;
    }
    ll p = 1LL;
    ll ans = 0LL;
    rep(i,40){
        if ((ab[i] - aa[i]) % 2 == 1) ans += p;
        p *= 2LL;
    }
    //printvec(aa); printvec(ab);
    cout << ans << endl;
}