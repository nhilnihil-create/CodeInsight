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
    vi n(4);
    rep(i,4) cin >> n.at(i);
    string res = "NO";
    set<ll> s;
    rep(i,4) s.insert(n.at(i));
    if(s.count(1)&&s.count(9)&&s.count(7)&&s.count(4)) res = "YES";
    cout << res << endl;
}