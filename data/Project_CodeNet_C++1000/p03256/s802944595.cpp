#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> p_ll;

template<class T>
void debug(T itr1, T itr2) { auto now = itr1; while(now<itr2) { cout << *now << " "; now++; } cout << endl; }
#define repr(i,from,to) for (int i=(int)from; i<(int)to; i++)
#define all(vec) vec.begin(), vec.end()
#define rep(i,N) repr(i,0,N)
#define per(i,N) for (int i=(int)N-1; i>=0; i--)

const ll MOD = pow(10,9)+7;
const ll LLINF = pow(2,61)-1;
const int INF = pow(2,30)-1;

vector<ll> fac;
void c_fac(int x=pow(10,6)+10) { fac.resize(x,true); rep(i,x) fac[i] = i ? (fac[i-1]*i)%MOD : 1; }
ll inv(ll a, ll m=MOD) { ll b = m, x = 1, y = 0; while (b!=0) { int d = a/b; a -= b*d; swap(a,b); x -= y*d; swap(x,y); } return (x+m)%m; }
ll nck(ll n, ll k) { return fac[n]*inv(fac[k]*fac[n-k]%MOD)%MOD; }
ll gcd(ll a, ll b) { if (a<b) swap(a,b); return b==0 ? a : gcd(b, a%b); }
ll lcm(ll a, ll b) { return a/gcd(a,b)*b; }


int main() {
  int N, M; cin >> N >> M;
  string s; cin >> s;

  set<int> adj[N];
  int count[N][2] = {};
  rep(i,M) {
    int a, b; cin >> a >> b; a--; b--;
    adj[a].insert(b);
    adj[b].insert(a);
  }

  rep(i,N) {
    for (auto x: adj[i]) {
      if (s[x]=='A') count[i][0]++;
      else count[i][1]++;
    }
  }

  stack<int> ng;
  bool use[N] = {}; fill_n(use,N,true);
  rep(i,N) if (!(count[i][0]&&count[i][1])) ng.push(i);

  while(ng.size()) {
    int now = ng.top(); ng.pop();
    // cout << endl << now << "->";
    use[now] = false;
    for (auto x: adj[now]) {
      // cout << x << " ";
      adj[x].erase(now);
      if (s[now]=='A') count[x][0]--;
      else count[x][1]--;
      if (!(count[x][0]&&count[x][1])) ng.push(x);
    }
    adj[now].clear();
  }
  // debug(use,use+N);
  // rep(i,N) cout << count[i][0] << " " << count[i][1] << endl;

  bool ok = false;
  rep(i,N) ok |= use[i];
  string result = ok ? "Yes" : "No";
  cout << result << endl;
  return 0;
}