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

    ll N, M;
    cin >> N >> M;

    vector<ll> P(N);
    vector<bool> ans(N, false);

    REP(i, N){
        ll p;
        cin >> p;
        p--;
        P[i] = p;
        if(i == p){
            ans[i] = true;
        }
    }

    // グラフ入力受取
    Graph G(N);
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    // 頂点 s をスタートとした探索
    vector<int> dist(N, -1);
    queue<int> que;

    for (int v = 0; v < N; ++v) {
        if (dist[v] != -1) continue; // v が探索済みならスルー

        map<ll, ll> M;
        
        dist[v] = 0, que.push(v);
        while (!que.empty()) {
            int v = que.front(); que.pop();
            if(M.count(v)){
                M[v]++;
            }
            else{
                M[v] = 1;
            }
            if(M.count(P[v])){
                M[P[v]]++;
            }
            else{
                M[P[v]] = 1;
            }
            for (auto nv : G[v]) {
                if (dist[nv] == -1) {
                    dist[nv] = dist[v] + 1;
                    que.push(nv);
                }
            }
        }
        for(auto iter=M.begin(); iter!=M.end(); iter++){
            if(iter->second == 2){
                ans[iter->first] = true;
            }
        }
    }
    ll count = 0;
    REP(i, N){
        if(ans[i]) count++;
    }
    cout << count << endl;
    return 0;
}