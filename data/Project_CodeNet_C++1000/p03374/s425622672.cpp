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
 
using namespace std;
int MOD = 1000000007;

signed main(){
    int n,c;
    cin >> n >> c;
    int ans = 0;

    int left1[100010] = {0};
    int left2[100010] = {0};
    int right1[100010] = {0};
    int right2[100010] = {0};

    vector<pair<int,int>> s;

    rep(i,n){
        int x,v;
        cin >> x >> v;
        s.push_back(MP(x,v));
    }
    int wal = s[0].se;
    left1[0] = max(0LL,wal-s[0].fi);
    left2[0] = max(0LL,wal-2*s[0].fi);
    ans = max(ans,left1[0]);
    for(int i = 1;i < n;i++){
        wal += s[i].se;
        left1[i] = max(left1[i-1],wal-s[i].fi);
        left2[i] = max(left2[i-1],wal-2*s[i].fi);
        ans = max(ans,left1[i]);
        // cerr << i << " " << ans << endl;
    }

    int war = s[n-1].se;
    right1[0] = max(0LL,war-c+s[n-1].fi);
    right2[0] = max(0LL,war-2*c+2*s[n-1].fi);
    ans = max(ans,right1[0]);
    for(int i = 1;i < n;i++){
        war += s[n-1-i].se;
        right1[i] = max(right1[i-1],war-c+s[n-1-i].fi);
        right2[i] = max(right2[i-1],war-2*c+2*s[n-1-i].fi);
        ans = max(ans,right1[i]);
        // cerr << i << " " << ans << endl;
    }

    for(int i = 0;i <= n-2;i++){
        ans = max(ans,left2[i]+right1[n-2-i]);
        //cerr << i << " " << ans << endl;
        ans = max(ans,left1[n-2-i]+right2[i]);
        // cerr << i << " " << ans << endl;
    }
    // cerr << "left1" << endl;
    // rep(i,n) cerr << left1[i] << endl;
    // cerr << "left2" << endl;
    // rep(i,n) cerr << left2[i] << endl;
    // cerr << "right1" << endl;
    // rep(i,n) cerr << right1[i] << endl;
    // cerr << "right2" << endl;
    // rep(i,n) cerr << right2[i] << endl;
    
    
    cout << ans << endl;

    return 0;   
}
// g++ -std=c++14 code1.cpp
// rm -r -f test;oj dl https://ddcc2019-final.contest.atcoder.jp/tasks/ddcc2019_final_a
// rm -r -f test;oj dl http://arc096.contest.atcoder.jp/tasks/arc096_b
