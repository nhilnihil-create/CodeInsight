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
    string s;
    cin >> s;
    string key = "keyence";
    string key2 = "keyence";
    string res = "NO";
    ll count = 0;
    rep(i,7){
        if(s.at(i)!=key.at(i)) break;
        count++;
    }
    rep(i,7){
        if(s.at(s.size()-1-i)!=key.at(6-i)) break;
        count ++;
    }
    if(count >= 7) res = "YES";
    cout << res << endl;
}