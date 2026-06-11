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

    int H, W;
    cin >> H >> W;
    char s[H+10][W+10] = {'.'};
    REP1(i, H+1)REP1(j, W+1) cin >> s[i][j];

    REP1(i, H+1){
        REP1(j, W+1){
            if((s[i-1][j] == '.') && (s[i+1][j] == '.') && (s[i][j-1] == '.') && (s[i][j+1] == '.') & (s[i][j] == '#')){
                // cout << i << " " << j << endl;
                // cout << s[i-1][j] << s[i+1][j] << s[i][j-1] << s[i][j+1]  << endl;
                // s[i][j] = ' ';
                cout << "No" << endl;
                return 0;
            }
        }
    }
    // REP1(i, H+1){
    //     REP1(j, W+1){
    //         cout << s[i][j];
    //     }cout << endl;
    // }
    cout << "Yes" << endl;
    return 0;

    

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