#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
typedef vector<ld> vld;
typedef vector<string> vstr;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
typedef priority_queue<ll, vector<ll>, greater<ll>> spqll;  // 小さい順に取り出し
typedef priority_queue<ll, vector<ll>, less<ll>> bpqll;     // 大きい順に取り出し

#define REP(i, n) for (ll i = 0; i < (ll)(n); i++)
#define IREP(i, v) for (auto i = (v).begin(); i != (v).end(); ++i)
#define TS to_string
#define ALL(v) (v).begin(), (v).end()
#define endl "\n"

ll INF = 1e9;
ll MOD = 1000000007;
ll LINF = 1e18;
ld EPS = 1e-9;
ld PI = M_PI;
vll dx = {1, 0, -1, 0, 1, -1, -1, 1};
vll dy = {0, 1, 0, -1, 1, 1, -1, -1};
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a;} //最大公約数
ll lcm(ll a, ll b) { return a / gcd(a, b) * b;}     //最小公倍数

void yes(){ cout << "YES" << endl;}
void no(){ cout << "NO" << endl;}

//-----------------------------------------
void bfs(ll s, vvll &graph, vll &d, ll &n, vll &c){
  vll seen(n,0);
  queue<ll> que;

  seen[s] = 1;
  que.push(s);
  ll j = 0;
  d[s] = c[j];
  j++;

  while(!que.empty()){
    ll t = que.front(); que.pop();
    seen[t] = 1;
    for(ll i = 0; i < graph[t].size(); i++){
      ll u = graph[t][i];
      if(seen[u] == 0){
        que.push(u);
        d[u] = c[j];
        j++;
      }
    }
  }
}
//-----------------------------------------
int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);

  ll n;
  cin >> n;

  vvll graph(n);
  REP(i,n-1){
    ll a, b;
    cin >> a >> b;
    a--; b--;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  vll c(n);
  REP(i,n) cin >> c[i];
  sort(ALL(c));
  reverse(ALL(c));

  ll ans = 0;
  vll d(n);

  bfs(0,graph,d,n,c);

  REP(i,n){
    if(i) ans += c[i];
  }

  cout << ans <<endl;

  REP(i,n){
    if(i) cout << " ";
    cout << d[i];
  }
  cout << endl;



  return 0;
}

