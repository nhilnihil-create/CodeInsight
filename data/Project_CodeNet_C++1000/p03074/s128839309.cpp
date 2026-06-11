#include <bits/stdc++.h>

using namespace std;

#define REP1(i,n) for(int i=1, i##_len=(n); i<i##_len; ++i)
#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define pow(x) x*x
#define ll long long
static const ll MAX = 1000000;
static const ll INFTY = 1e12;
static const ll MOD = 1000000007;

template < typename T > inline string toString( const T &a ) { ostringstream oss; oss << a; return oss.str(); };

struct edge {
    ll to, cost;
};

using Graph = vector<vector<int>>;
using _Graph = vector<vector<edge>>;


const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

// 深さ優先探索
vector<bool> seen;
vector<int> colors;

int H, W, N;
int sx, sy, gx, gy; 
vector<vector<char>> field;
vector<vector<int>> dist;
//vector<pair<int, int>> gx, gy;
deque<pair<int, int>> que;

typedef vector<vector<int> > Matrix;

const int INF = 100000000;


int main() {

    ll N, K;
    string S;
    cin >> N >> K;
    cin >> S;
    vector<int> num;

    int pos = 0;

    REP(i, S.length()-1){
      if(S[i] != S[i+1]){
        num.push_back(i-pos+1);
        pos = i+1;
      }      
    }
    num.push_back(S.length()-pos);
    if(S[0]=='0')num.insert(num.begin(), 0);
    if(S[S.length()-1]=='0')num.push_back(0);

    int span = 2*K+1;
    // if(span >= num.size()-1)span=num.size()-1;
    vector<int> sum(num.size()+1, 0);
    REP(i, num.size()){
      sum[i+1] = sum[i] + num[i];
    }

    int max_ = 0;
    for(int i = sum.size()-1; i >= 0; i-=2){
      // cout << span << endl;
      if(i-span < 0){
        max_ = max(max_, sum[i]-sum[0]);
        
      }
      else {
        max_ = max(max_, sum[i]-sum[i-span]);
      }
      // cout << max_ << endl;
    }

    // REP(i, sum.size()){
    //   cout << sum[i] << " ";
    // }
    cout << max_ << endl;

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
