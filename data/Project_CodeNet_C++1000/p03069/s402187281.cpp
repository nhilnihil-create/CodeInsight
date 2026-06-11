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
    string s;
    cin >> n >> s;
    ll sumw = 0, sumb = 0;
    vi csumw(n), csumb(n);
    rep(i,n){
        if(s.at(i)=='.') sumw++;
        if(s.at(i)=='#') sumb++;
        csumw.at(i) = sumw;
        csumb.at(i) = sumb;
    }
    vi res(n+1);
    res.at(0) = sumw;
    rep(i,n){
        res.at(i+1) = csumb.at(i) + sumw - csumw.at(i);
    }
    sort(res.begin(), res.end());
    cout << res.at(0) << endl;
}