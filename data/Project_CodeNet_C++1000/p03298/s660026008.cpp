#include "bits/stdc++.h"
 
typedef long long ll;
#define int ll
#define fi first
#define se second
#define SORT(a) sort(a.begin(),a.end())
#define rep(i,n) for(int i = 0;i < (n) ; i++) 
#define REP(i,n) for(int i = 0;i < (n) ; i++) 
#define MP(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define INF LLONG_MAX/2
#define all(x) (x).begin(),(x).end()
#define debug(x) cerr<<#x<<": "<<x<<endl
#define debug_vec(v) cerr<<#v<<":";rep(i,v.size())cerr<<" "<<v[i];cerr<<endl
using namespace std;
int MOD = 1000000007;

signed main(){
    int n;
    string s;
    cin >> n >> s;

    string s1 = s.substr(0,n);
    string s2 = "";
    rep(i,n){
        s2.pb(s[2*n-1-i]);
    }
    // cerr << s1 << endl;
    // cerr << s2 << endl;
    map<pair<string,string>,int> m1,m2;
    for(int i = 0;i < (1LL<<n);i++){
        string t1 = "";
        string t2 = "";
        string t3 = "";
        string t4 = "";
        for(int j = 0;j < n;j++){
            if(i&(1LL<<j)){
                t1.push_back(s1[j]);
                t3.push_back(s2[j]);
            }else{
                t2.push_back(s1[j]);
                t4.push_back(s2[j]);
            }
        }
        m1[MP(t1,t2)]++;
        m2[MP(t3,t4)]++;
    }
    //for(auto x:m1)cerr << (x.fi).fi << " " << (x.fi).se << endl;
    int ans = 0;
    for(auto x:m1){
        auto itr = m2.find(x.fi);
        if(itr != m2.end()){
            ans += (x.se) * (itr->se);
        }
    }
    cout << ans << endl;





    
    
    return 0; 
}

// g++ -std=c++14 code1.cpp
// rm -r -f test;oj dl https://agc026.contest.atcoder.jp/tasks/agc026_c
// rm -r -f test;oj dl http://abc107.contest.atcoder.jp/tasks/abc107_b