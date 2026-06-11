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

using Graph = vector<set<int>>;
using _Graph = vector<vector<edge>>;


const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

// 深さ優先探索
vector<bool> seen;
vector<int> colors;

// int H, W, N;
int sx, sy, gx, gy; 
vector<vector<char>> field;
vector<vector<int>> dist;
//vector<pair<int, int>> gx, gy;
deque<pair<int, int>> que;

typedef vector<vector<int> > Matrix;

const int INF = 100000000;


int main() {

  int N;
  cin >> N;

  double en = 0.0, bit = 0.0;

  REP(i, N){
    double n;
    string s;
    cin >> n >> s;
    if(s == "JPY"){
      en += n;
    }else{
      bit += n;
    }
  }
  double ans = en + bit * 380000.0;

  cout << ans << endl;



}


/*
みんな、くるくるぱーにな〜れ
　∧＿∧　
（｡･ω･｡)つ━☆・*。
⊂　　 ノ 　　　・゜+.
　しーＪ　　　°。+ *´¨)
　　　　　　　　　.· ´¸.·*´¨) ¸.·*¨)
　　　　　　　　　　(¸.·´ (¸.·'* ☆
*/
