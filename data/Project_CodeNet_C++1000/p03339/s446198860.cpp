#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define REP1(i,n) for(int i=1, i##_len=(n); i<i##_len; ++i)
#define ll long long
static const int MAX = 10000;
static const ll INFTY = 1e12;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const ll MRINF = 5000000000000000;

int main() {

    ll N;
    cin >> N;
    string S;
    cin >> S;
    vector<ll> left(N, 0), right(N, 0);

    if(S[0]=='W'){
        left[0] = 1;
    }else{
        left[0] = 0;
    }
    REP1(i, N){
        if(S[i]=='W'){
            left[i] = left[i-1]+1;
        }else{
            left[i] = left[i-1];
        }
    }

    if(S[N-1]=='E'){
        right[N-1] = 1;
    }else{
        right[N-1] = 0;
    }
    for(ll i = N-2; i>=0; i--){
        if(S[i]=='E'){
            right[i] = right[i+1]+1;
        }else{
            right[i] = right[i+1];
        }
    }

    // REP(i, N){
    //     cout << left[i] << " " << right[i] << endl;
    // }
    vector<ll> ans(N);
    ans[0] = right[1];
    ans[N-1] = left[N-2];
    REP1(i, N-1){
        ll l = left[i-1];
        ll r = right[i+1];
        ans[i] = l+r;
    }
    sort(ans.begin(), ans.end());
    cout << ans[0] << endl;

}
/*
                   _ooOoo_
                  o8888888o
                  88" . "88
                  (| -_- |)
                  O\  =  /O
               ____/`---'\____
             .'  \\|     |//  `.
            /  \\|||  :  |||//  \
           /  _||||| -:- |||||-  \
           |   | \\\  -  /// |   |
           | \_|  ''\---/''  |   |
           \  .-\__  `-`  ___/-. /
         ___`. .'  /--.--\  `. . __
      ."" '<  `.___\_<|>_/___.'  >'"".
     | | :  `- \`.;`\ _ /`;.`/ - ` : | |
     \  \ `-.   \_ __\ /__ _/   .-` /  /
======`-.____`-.___\_____/___.-`____.-'======
                   `=---='
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
         pass System Test!
*/