#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> p_ll;

template<class T>
void debug(T itr1, T itr2) { auto now = itr1; while(now<itr2) { cout << *now << " "; now++; } cout << endl; }
#define repr(i,from,to) for (ll i=(ll)from; i<(ll)to; i++)
#define all(vec) vec.begin(), vec.end()
#define rep(i,N) repr(i,0,N)
#define per(i,N) for (ll i=(ll)N-1; i>=0; i--)

const ll MOD = pow(10,9)+7;
const ll LLINF = pow(2,61)-1;
const ll INF = pow(2,30)-1;

vector<ll> fac;
void c_fac(ll x=pow(10,6)+10) { fac.resize(x,true); rep(i,x) fac[i] = i ? (fac[i-1]*i)%MOD : 1; }
ll inv(ll a, ll m=MOD) { ll b = m, x = 1, y = 0; while (b!=0) { ll d = a/b; a -= b*d; swap(a,b); x -= y*d; swap(x,y); } return (x+m)%m; }
ll nck(ll n, ll k) { return fac[n]*inv(fac[k]*fac[n-k]%MOD)%MOD; }
ll modpow(ll x, ll p) { ll result = 1, now = 1, pm = x; while (now<=p) { if (p&now) { result = result * pm % MOD; } now*=2; pm = pm*pm % MOD; } return result; }
ll gcd(ll a, ll b) { if (a<b) swap(a,b); return b==0 ? a : gcd(b, a%b); }
ll lcm(ll a, ll b) { return a/gcd(a,b)*b; }

int main() {
  ll H, W, N; cin >> H >> W >> N;
  ll sr, sc; cin >> sr >> sc;
  string S, T; cin >> S >> T;
  string result = "YES";
  ll L = 1, R = W, U = 1, D = H;
  per(i,N) {
    if (i!=N-1) {
      if (T[i]=='L') R = min(W,R+1);
      else if (T[i]=='R') L = max(1ll,L-1);
      else if (T[i]=='U') D = min(H,D+1);
      else if (T[i]=='D') U = max(1ll,U-1);
    }
    if (S[i]=='L') L++;
    else if (S[i]=='R') R--;
    else if (S[i]=='U') U++;
    else if (S[i]=='D') D--;

    if (L>R||U>D) { result = "NO"; break; }
    // cout << L << "-" << R << " " << U << "-" << D << endl;
  }

  if (L>sc||R<sc||U>sr||D<sr) result = "NO";
  cout << result << endl;
  return 0;
}