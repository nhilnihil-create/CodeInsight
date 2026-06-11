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

    int N;
    cin >> N;
    vector<string> W(N);
    map<string, int> str;
    vector<char> start(N), end(N);
    REP(i, N){
        cin >> W[i];
        str[W[i]]++;
        start[i] = W[i][0];
        end[i] = W[i][W[i].length()-1];
    }
    REP1(i, N){
        // cout << start[i] << " " << end[i-1] << endl;
        if(start[i] != end[i-1]){
            cout << "No" << endl;
            return 0;
        }
    }
    for(auto itr = str.begin(); itr != str.end(); itr++){
        if(itr->second != 1){
            cout << "No" << endl;
            return 0;         
        }
    }

    cout << "Yes" << endl;
    return 0;  
 

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

