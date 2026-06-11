#include <bits/stdc++.h>
using namespace std;

// 型定義
typedef long long ll;
typedef pair<ll, ll> P;
bool operator>(const P a,const P b){return a.second > b.second;};//演算子オーバーロード

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

vector<ll> C;
vector<ll> ans;
vector<bool> seen; 
queue<ll> que;
ll score = 0;
ll max_score = 0;
ll max_id = -1;

// DFSのための再帰関数
void dfs(const Graph &G, ll v, ll step) {
    seen[v] = true;
    ans[v] = que.front();
    que.pop();
    if(step != 0) score += ans[v];
    for (auto next_v : G[v]) { 
        if (seen[next_v]) continue;
        dfs(G, next_v, step+1); // 再帰的に値を追加していく
    }
}

int main()
{
    cout << fixed << setprecision(15);
    ll N;
    cin >> N;

    C.resize(N);
    ans.resize(N);
    
    // グラフ
    Graph G(N);

    REP(i, N-1){
        int a, b;
        cin >> a >> b;
        G[a-1].push_back(b-1);
        G[b-1].push_back(a-1);
    }
    REP(i, N){
        cin >> C[i];
    }
    sort(C.begin(), C.end(), greater<ll>());

    // REP(i, 1){
    //     seen.assign(N, false);
    //     REP(j, N){
    //         que.push(C[j]);
    //     }
    //     score = 0;
    //     dfs(G, i, i, 0);

    //     if(score > max_score){
    //         max_score = score;
    //         max_id = i;
    //     }
    // }
    seen.assign(N, false);
    REP(j, N){
        que.push(C[j]);
    }
    score = 0;
    dfs(G, 0, 0);

    if(score > max_score){
        max_score = score;
        max_id = 0;
    }

    cout << max_score << endl;
    REP(i, N){
        if(i == N-1){
            cout << ans[i] << endl;
        }
        else{
            cout << ans[i] << " ";
        }
    }
    return 0;
}