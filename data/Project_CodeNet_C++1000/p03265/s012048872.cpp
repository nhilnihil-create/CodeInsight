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

    int x1, x2, x3, x4, y1, y2, y3, y4;
    cin >> x1 >> y1 >> x2 >> y2;

    if(x2>=x1){
        if(y2>=y1){
            x3 = x2-(y2-y1);
            y3 = y2+(x2-x1);
            x4 = x1-(y2-y1);
            y4 = y1+(x2-x1);
        }else{
            x3 = x2+(y1-y2);
            y3 = y2+(x2-x1);
            x4 = x1+(y1-y2);
            y4 = y1+(x2-x1);
        }
    }else{
        if(y2>=y1){
            x3 = x2-(y2-y1);
            y3 = y2-(x1-x2);
            x4 = x1-(y2-y1);
            y4 = y1-(x1-x2);
        }else{
            x3 = x2+(y1-y2);
            y3 = y2-(x1-x2);
            x4 = x1+(y1-y2);
            y4 = y1-(x1-x2);
        }       
    }

    cout << x3 << " " << y3 << " " << x4 << " " << y4 << endl;
 

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

