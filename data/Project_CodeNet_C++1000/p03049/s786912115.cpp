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
    vector<string> s(n);
    rep(i,n) cin >> s.at(i);
    ll res = 0;
    rep(i,n){
        rep(j,s.at(i).size()-1){
            if(s.at(i).at(j)=='A' && s.at(i).at(j+1)=='B') res++;
        }
    }
    // 1. Bで始まってAで終わる
    // 2. Bで始まってA以外で終わる
    // 3. B以外で始まってAで終わる
    // 2,3があれば1.の数が答え、なければ1.-1が答え
    ll p1=0,p2=0,p3=0;
    rep(i,n){
        if(s.at(i).at(0)=='B' && s.at(i).at(s.at(i).size()-1)=='A'){
            p1++;
        }else if(s.at(i).at(0)=='B' && s.at(i).at(s.at(i).size()-1)!='A'){
            p2++;
        }else if(s.at(i).at(0)!='B' && s.at(i).at(s.at(i).size()-1)=='A'){
            p3++;
        }
    }
    if(p1>0 && p2==0 && p3==0){
        res += p1-1;
    }else{
        res += p1 + min(p2,p3);
    }
    cout << res << endl;
}