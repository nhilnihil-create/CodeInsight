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
  ll N; cin >> N;
  ll result[N];

  if (N==3) { cout <<  "2 3 25" << endl; return 0; }
  else if (N==4) { cout <<  "2 3 5 20" << endl; return 0; }
  else if (N==5) { cout <<  "2 3 5 20 30" << endl; return 0; }
  else {
    rep(i,N) {
      if (i%4==0) result[i] = 6*(i/4) + 2;
      else if (i%4==1) result[i] = 6*(i/4) + 3;
      else if (i%4==2) result[i] = 6*(i/4) + 4;
      else if (i%4==3) result[i] = 6*(i/4) + 6;
    }
    if (N%8==1) result[N-1] += 4;
    else if (N%8==2) result[N-1] += 1;
    else if (N%8==3) result[N-2] += 3;
    else if (N%8==4) result[N-3] += 9;
    else if (N%8==5) result[N-4] += 7;
    else if (N%8==6) result[N-2] += 4;
  }
  debug(result,result+N);
  // cout << result << endl;
  return 0;
}