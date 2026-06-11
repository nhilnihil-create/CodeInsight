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
int n,m;
vector<int> p[100010];
int used[100010] = {0};
int c = 1;
void dfs(int g,int d){
    if(used[g] == 0){
        used[g] = d;
        for(auto x:p[g]){
            dfs(x,-1*d);
        }
    }else{ 
        if(used[g] != d){
            c = 0;
        }
        return;
    }
    return;
}

signed main(){
    cin >> n >> m;
    rep(i,m){
        int a,b;
        cin >> a >> b;
        p[a-1].push_back(b-1);
        p[b-1].push_back(a-1);
    }
    dfs(0,1);
    if(c == 0){
        cout << n*(n-1)/2 - m << endl;
        return 0;
    }
    int cnt = 0;
    rep(i,n){
        if(used[i] == 1){
            cnt++;
        }
    }
    cout << cnt*(n-cnt) - m << endl;

    
    return 0; 
}

// g++ -std=c++14 code1.cpp
// rm -r -f test;oj dl https://arc064.contest.atcoder.jp/tasks/arc064_c
// rm -r -f test;oj dl http://code-festival-2017-qualb.contest.atcoder.jp/tasks/code_festival_2017_qualb_c
