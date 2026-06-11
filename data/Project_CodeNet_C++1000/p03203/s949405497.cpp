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

struct coord { int X; int Y; };

int main() {
  int H, W, N; cin >> H >> W >> N;
  coord c[N]; rep(i,N) { int X, Y; cin >> X >> Y; X--; Y--; c[i] = {X,Y}; }
  sort(c,c+N,[](const coord &x, const coord &y){return x.Y<y.Y||(x.Y==y.Y&&x.X<y.X);});
  map<int, int> pos; pos[0] = 0;
  rep(i,N) {
    if (pos.count(c[i].Y)==0) {
      int tf = pos.rbegin()->first, ts = pos.rbegin()->second;
      pos[c[i].Y] = ts + (c[i].Y-tf);
    }
    if (pos[c[i].Y]==c[i].X) pos[c[i].Y]++;
  }
  // for (auto x: pos) cout << x.first << "->" << x.second << " "; cout << endl;  // cout << result << endl;
  int result = H;
  rep(i,N) if (pos[c[i].Y]<c[i].X) result = min(result,c[i].X);
  cout << result << endl;
  return 0;
}