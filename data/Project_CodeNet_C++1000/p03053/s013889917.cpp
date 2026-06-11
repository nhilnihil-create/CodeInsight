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

ll dx[] = {1, -1, 0, 0};
ll dy[] = {0, 0, 1, -1};

int main()
{
    cout << fixed << setprecision(15);
    ll H, W;
    cin >> H >> W;

    vector<vector<char>> A(H, vector<char>(W));

    // キューを準備
    queue<P> que;

    vector<vector<ll>> v(H, vector<ll>(W, -1));
    REP(i, H){
        REP(j, W){
            cin >> A[i][j];
            if(A[i][j] == '#'){
                v[i][j] = 0;
                que.push(P(i, j));
            }
        }
    }

    while(true) {
        //　もしも探索地点がゴールならば現在の歩数を探索終了
        if(que.empty()) {
            // cout << "empty" << endl;
            // return 0;
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
                || v[nx][ny] != -1) continue;
            // 未探索だったら、キューに入れて現在の距離を記録
            que.push(P(nx, ny));
            v[nx][ny] = s+1;
        }
    }

    ll ans = 0;
    REP(i, H){
        REP(j, W){
            ans = max(ans, v[i][j]);
        }
    }
    cout << ans << endl;
}