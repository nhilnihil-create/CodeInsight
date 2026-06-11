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

const ll INF = 1e18;

int main() {

  ll N, M;
  cin >> N >> M;
  vector<ll> P(M), Y(M);
  vector<vector<pair<ll, ll>>> city(N);

  REP(i, M){
      cin >> P[i] >> Y[i];
      city[P[i]-1].push_back({Y[i], i});
  }
    vector<pair<ll, ll>> ans(M);
  REP(i,N){
    //   REP(j,M){
    //       if(P[j]==i+1){
    //           city.push_back({Y[j], j});
    //       }
    //   }
      sort(city[i].begin(), city[i].end());
    //   REP(j,M){
    //       cout << city[j].first << " " << city[j].second << endl;
    //   }
      REP(j, city[i].size()){
          ans[city[i][j].second].first = i+1;
          ans[city[i][j].second].second = j+1;
      }
  }

  REP(i, M){
      cout << setw(6) << setfill('0') << ans[i].first << setw(6) << setfill('0') << ans[i].second << endl;
  }
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

