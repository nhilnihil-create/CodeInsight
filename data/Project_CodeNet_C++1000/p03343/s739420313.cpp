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
    int n,k,q;
    cin >> n >> k >> q;
    vector<int> a(n);
    rep(i,n)cin >> a[i];
    vector<int> b = a;
    SORT(b);
    int res = INF;
    rep(i,n){
        vector<int> c = a;
        int mini = b[i];
        vector<int> d[2001];
        int cnt = 0;
        rep(i,n){
            if(c[i] >= mini){
                d[cnt].pb(c[i]);
            }else{
                cnt++;
            }
        }
        vector<int> ans;
        rep(i,2001){
            int num =  (int)(d[i].size()) + 1 - k;
            if(num <= 0)continue;
            else{
                SORT(d[i]);
                rep(j,num){
                    ans.pb(d[i][j]);
                }
            }
        }
        if(ans.size() < q)continue;
        else{
            SORT(ans);
            res = min(res,ans[q-1]-ans[0]);
        }
    }
    cout << res << endl;


    return 0; 
}

// g++ -std=c++14 code1.cpp
// rm -r -f test;oj dl https://yahoo-procon2019-qual.contest.atcoder.jp/tasks/yahoo_procon2019_qual_d
// rm -r -f test;oj dl http://arc098.contest.atcoder.jp/tasks/arc098_c