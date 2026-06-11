#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vint;
typedef vector<double> vd;
typedef vector<ll> vll;
typedef vector<string> vstr;
typedef vector<vector<int>> vvint;
typedef vector<pair<int, int>> vpii;
typedef vector<pair<ll, ll>> vpll;
typedef priority_queue<int, vector<int>, greater<int>> spqint; //小さい順に取り出し
typedef priority_queue<ll, vector<ll>, greater<ll>> spqll;     //小さい順に取り出し
typedef priority_queue<int, vector<int>, less<int>> bpqint;    //大きい順に取り出し
typedef priority_queue<ll, vector<ll>, less<ll>> bpqll;        //大きい順に取り出し

#define REP(i, n) for (ll i = 0; i < (ll)(n); i++)
#define FOR(i, a, b) for (ll i = (ll)a; i < (ll)b; i++)
#define IREP(i, v) for (auto i = (v).begin(); i != (v).end(); i++)
#define FI first
#define SE second
#define MP make_pair
#define MT make_tuple
#define PB push_back
#define PF push_front
#define TS to_string
#define BS binary_search
#define LB lower_bound
#define UB upper_bound
#define NP next_permutation
#define ALL(v) (v).begin(), (v).end()
#define SZ(x) (ll) x.size()
#define SP(x) setprecision((ll)x)


int INF = 1e9;
int NIL = -1;
ll MOD = 1000000007;
ll LINF = 1e18;
double EPS = 1e-9;
double PI = M_PI;
int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; } //最大公約数
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }     //最小公倍数

void yes(){ cout << "Yes" << endl;}
void no(){ cout << "No" << endl;}
//-----------------------------------------
const ll MAX_V = 1e6 + 1 ;

struct edge{
  ll to ; 
  ll cost ;
  //iからの行き先とそのコストの情報
};

ll n ;
vector<edge> G[MAX_V] ;
//G[i]...iからの行き先(to)とコスト(cost)の情報を持つ
ll d[MAX_V] ;
//d[i]...sからiへ行くのにかかるコストの最小

vector<ll> par ;
//par[i]...iの一個前


void dijkstra(int s){
  priority_queue<pii, vector<pii>, greater<pii>> que;
  //pair<sからiへ行くのの暫定最小コスト、i>の優先度付きキュー
  REP(i,n){
    d[i] = INF ;
    par.PB(i) ;
    //はじめコストはINFとして初期化
  }
  d[s] = 0 ;
  que.push(MP(0,s)) ;
  //自身へのコストは0としてqueへ入れる
  
  while(!que.empty()){
    pii p = que.top() ;
    que.pop() ;
    int v = p.SE ;
    //queが空になるまで取り出す
    if(d[v]<p.FI){
      //すでにそれ以下があれば見る必要はない
      continue ;
    }
    REP(i,SZ(G[v])){
      //vを経由した行き先について
      edge e = G[v][i] ;
      if(d[e.to]>d[v]+e.cost){
        //vを経由した方がコストが小さいなら更新し、queに入れる
        d[e.to] = d[v]+e.cost ;
        par[e.to] =  v ;
        que.push(MP(d[e.to],e.to)) ;
      }
    }
  }
}

//頂点tへの最短路
vector<int> get_path(int t){
    vector<int> path;
    int i = t ;
    while(i!=par[i]){
      path.PB(i) ;
      i = par[i] ;
    }
    reverse(ALL(path)) ;
    return path ;
}
//-----------------------------------------
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    std::chrono::system_clock::time_point start,end;
    start = std::chrono::system_clock::now();

    ll h, w ;
    cin >> h >> w ;
    n = h*w+1 ;
    vector<vector<char>> grid(h,vector<char>(w)) ;
    REP(i,h){
        string s ;
        cin >> s ;
        REP(j,w){
            grid[i][j] = s[j] ;
        }
    }
    bool f = true ;
    REP(i,h){
        REP(j,w){
            if(grid[i][j]=='.'){
                f = false ;
            }
        }
    }
    if(f){
        cout << 0 <<endl;
        return 0 ;
    }

    REP(i,h){
        REP(j,w){
            if(grid[i][j]=='#'){
                edge e = {0,0} ;
                edge f = {i*w+j+1,0} ;
                G[i*w+j+1].PB(e) ;
                G[0].PB(f) ;
                continue ;
            }
            int x, y ;
            x = i ;
            y = j ;
            REP(k,4){
                int xx = x + dx[k] ;
                int yy = y + dy[k] ;
                if(0 <= xx && xx < h && 0 <= yy && yy< w){
                    edge e = {xx*w+yy+1,1} ;
                    edge f = {x*w+y+1,1} ;
                    G[x*w+y+1].PB(e) ;
                    G[xx*w+yy+1].PB(f) ;
                }
            }
        }
    }

    dijkstra(0);

    sort(d,d+MAX_V) ;

    cout << d[MAX_V-1] <<endl;




    end = std::chrono::system_clock::now();
    auto elapsed = std::chrono::duration_cast< std::chrono::milliseconds >(end - start).count();
    //std::cout << elapsed <<"ms"<< std::endl;

    

    return 0;
}

