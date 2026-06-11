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

int main()
{
    cout << fixed << setprecision(15);

    ll N, K;
    cin >> N >> K;
    vector<vector<ll> > s(N); // s[i] := 種類 i の美味しさの集合

    for (ll i = 0; i < N; ++i) {
        ll t, d;
        cin >> t >> d;
        t--;
        s[t].push_back(d);
    }

    // 各種類について、美味しい順に並べる
    for (auto &v : s) {
        sort(v.begin(), v.end(), greater<ll>());
        if (v.empty()) v.push_back(-INF); // 番兵
    }

    // 「美味しさの最大値」の大きいネタ順
    sort(s.begin(), s.end(), [&](vector<long long> a, vector<long long> b) {
            return a[0] > b[0];});
 
    // まず K 種類選ぶ場合
    ll cur = 0;
    priority_queue<ll> que;
    for (ll i = 0; i < K; ++i) {
        cur += s[i][0];
        // 最初の一つ以外はqueに入れる
        for (int j = 1; j < s[i].size(); ++j) que.push(s[i][j]);
    }
    // 選ばれていない集合はすべてqueに入れる
    for (int i = K; i < N; ++i){
        for (int j = 0; j < s[i].size(); ++j){
            que.push(s[i][j]);
        }
    }

    // 走査
    // 初期値は別の集合からK個選んだとき
    ll res = cur + K*K;

    // 一つずつ集合を減らしていく
    for (ll x = K-1; x >= 1; --x) {
        ll v = s[x][0]; // 今集合に入っている値で一番小さいもの
        ll w = que.top(); // 集合に入っていないもので一番大きいもの
        if (v < w) {
            que.pop(); cur += w;
            que.push(v); cur -= v;
        }
        res = max(res, cur + x*x);
    }
    cout << res << endl;
    return 0;
}