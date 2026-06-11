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

    ll n;
    cin >> n;
    map<ll, ll> v1, v2;
    REP(i, n){
        if(i%2==0){
            ll v;
            cin >> v;
            v1[v]++;
        }
        else {
            ll v;
            cin >> v;
            v2[v]++;
        }
    }

    vector<pair<ll, ll>> v1_, v2_;

    for(auto itr = v2.begin(); itr != v2.end(); ++itr) {
        v2_.push_back({itr->second, itr->first});
    }
    for(auto itr = v1.begin(); itr != v1.end(); ++itr) {
        v1_.push_back({itr->second, itr->first});
    }
    sort(v1_.begin(), v1_.end(), greater<pair<ll, ll>>());
    sort(v2_.begin(), v2_.end(), greater<pair<ll, ll>>());

    ll ans;
    if(v1_[0].second == v2_[0].second){
        if(v1_.size()==1 && v2_.size()==1){
            ans = n/2;
        }else{

            ll ans1 = (n/2 - v1_[0].first) + (n/2 - v2_[1].first);
            ll ans2 = (n/2 - v2_[0].first) + (n/2 - v1_[1].first);

            ans = min(ans1,ans2);
            // ans = 0;
        }
    }else{
        ans = (n/2 - v1_[0].first) + (n/2 - v2_[0].first);
    }

    

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

