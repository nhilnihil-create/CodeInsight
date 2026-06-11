#include <bits/stdc++.h>
using namespace std;

// 型定義
typedef long long ll;
typedef pair<ll, ll> P;

// forループ
#define REP(i,n) for(ll i=0; i<(ll)(n); ++i)

// 定数宣言
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

// グラフ表現
using Graph = vector<vector<int>>;

// グラフの辺表現
using Edge = map<pair<int,int>,int>;

// n次元配列の初期化。第２引数の型のサイズごとに初期化していく。
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

// 最大公約数
ll gcd(ll a,ll b){
   if (a%b == 0) return(b);
   else return(gcd(b, a%b));
}

// 最小公倍数
ll lcm(ll a, ll b){
    return a*b/gcd(a, b);
}

char c[51][51];
int v[51][51];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main()
{
    cout << fixed << setprecision(15);
    ll H, W;
    cin >> H >> W;

    ll black = 0;
    ll white = 0;
    REP(i, H) {
        REP(j, W) {
            cin >> c[i][j];
            // はじめは全ての頂点を到達不可に
            v[i][j] = -1;

            if(c[i][j] == '.') white++;
            if(c[i][j] == '#') black++;
        }
    }

    if(c[0][0] == '#'){
        cout << -1 << endl;
        return 0;
    }
    if(c[H-1][W-1] == '#'){
        cout << -1 << endl;
        return 0;
    }

    // キューを準備
    queue<P> que;
    // 探索の初期値を入れる
    que.push(P(0, 0));
    v[0][0] = 0;

    while(true) {
        //　もしも探索地点がゴールならば現在の歩数を探索終了
        if(que.empty()) {
            break;
        }
        // キューの中身を取り出す
        P p = que.front(); que.pop();
        int x = p.first;
        int y = p.second;
        int s = v[x][y];

        
        // 4方向へ繰り返す
        REP(i, 4) {
            int nx = x+dx[i];
            int ny = y+dy[i];
            // 移動すると範囲外になったり、#だったり、探索済みだったら終了する
            if(nx < 0 || nx >= H || ny < 0 || ny >= W
                || v[nx][ny] != -1 || c[nx][ny] == '#') continue;
            // 未探索だったら、キューに入れて現在の距離を記録
            que.push(P(nx, ny));
            v[nx][ny] = s+1;
        }
    }
    if(v[H-1][W-1] == -1){
        cout << -1 << endl;
        return 0;
    }
    cout << white - (v[H-1][W-1]+1) << endl;
    return 0;
}