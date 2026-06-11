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

    int N; cin >> N;
    string S; cin >> S;
    int ans = 0;
    int ansnum = 1;

    REP1(i, S.length()-1){
        string s1, s2;
        s1 = S.substr(0, i);
        s2 = S.substr(i, S.length()-i);
        int res = 0;
        map<char, int> s1_;
        REP(j, s1.length()){
            s1_[s1[j]]++;
        }
        for(auto itr = s1_.begin(); itr != s1_.end(); ++itr){
            char t = itr->first ;
            REP(k, s2.length()){
                if(t == s2[k]){
                    res++;
                    break;
                }
            }
        }
        if(res > ans){
            ansnum = i;
            ans = res;
        }
        // ans = max(ans, res);
    }
    cout << ans << endl;


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