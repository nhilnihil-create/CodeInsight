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
  int N; cin >> N;
  ll A[N]; rep(i,N) cin >> A[i];

  bool isone = true;
  repr(i,1,N) isone &= A[i]>A[i-1];
  if (isone) {
    cout << 1 << endl;
    return 0;
  }

  ll l = 2, r = N;
  while (l!=r) {
    ll mid = (l+r)/2;
    map<ll, ll> now;
    bool ok = true;
    rep(i,N) {
      if (i!=0) {
        if (now.size()==0) now[A[i]-1] = 1; 
        else {
          if (A[i-1]<A[i]) continue;
          else if (A[i-1]>A[i]) {
            auto p = now.upper_bound(A[i]-1);
            now.erase(p,end(now));
          }
          now[A[i]-1]++;
          ll pos = A[i]-1;
          while (now[pos]==mid) {
            now.erase(pos); now[pos-1]++;
            pos--;
          }
        }
      }
      if (now.count(-1)) {
        ok = false;
        break;
      }
    }
    // cout << l << " " << mid << " " << r << endl;
    // for (auto x: now) cout << x.first << "->" << x.second << " "; cout << endl;
    if (ok) r = mid;
    else l = mid+1;
  }
  ll result = l;
  cout << result << endl;
  return 0;
}