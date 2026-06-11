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

    int n;
    cin >> n;
    int a[60] = {0};
    rep(i,n)cin >> a[i];
    int maxi = 0;
    int flag = -1;
    rep(i,n){
        if(maxi < abs(a[i])){
            maxi = abs(a[i]);
            flag = i;
        }
    }
    if(flag == -1){
        cout << 0 << endl;
        return 0;
    }

    vector<pair<int,int>> ans;
    if(a[flag] < 0){
        for(int i = n-2;i >= 0;i--){
            if(a[i] > a[i+1]){
                ans.pb(MP(flag,i));
                a[i] += a[flag];
                if(a[i] < a[flag])flag = i;
            }
            if(a[i] > a[i+1]){
                ans.pb(MP(flag,i));
                a[i] += a[flag];
                if(a[i] < a[flag])flag = i;
            }
        }
    }else{
        for(int i = 1;i <= n-1;i++){
            if(a[i-1] > a[i]){
                ans.pb(MP(flag,i));
                a[i] += a[flag];
                if(a[i] > a[flag])flag = i;
            }
            if(a[i-1] > a[i]){
                ans.pb(MP(flag,i));
                a[i] += a[flag];
                if(a[i] > a[flag])flag = i;
            }
        }
    }

    cout << ans.size() << endl;
    for(auto x:ans){
        cout << x.fi+1 << " " << x.se+1 << endl;
    }

  	rep(i,n)cerr << a[i] << endl;


    return 0;   
}

// g++ -std=c++14 code1.cpp
// rm -r -f test;oj dl https://abc081.contest.atcoder.jp/tasks/arc086_b
// rm -r -f test;oj dl http://yahoo-procon2017-qual.contest.atcoder.jp/tasks/yahoo_procon2017_qual_c