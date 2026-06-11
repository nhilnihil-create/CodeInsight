#include <bits/stdc++.h>
#include <unistd.h>
#include <cctype>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <cmath>
#define SIZE 300005
#define MOD 1000000007LL
#define EPS 1e-10
#define INF 1 << 30
#define LLINF LLONG_MAX/3
#define REP(i,n) for(int i=0;i<n;i++)
#define FOR(i,a,n) for(int i=a;i<n;i++)
#define UP(i,a,b) for(int i=a;i<=b;i++)
#define DOWN(i,b,a) for(int i=b;i>=a;i--)
#define SET(a,c) memset(a,c,sizeof a)
#define BIT(i,j) ((i)>>(j))&1
#define ALL(o) (o).begin(), (o).end()
#define ERASE(o) (o).erase(unique((o).begin(),(o).end()), (o).end())
#define SQ(x) ((x)*(x))
using namespace std;
using ll = long long;
using Pll = pair<ll,ll>;
using Pii = pair<int,int>;
using Pdd = pair<double,double>;
using dcomplex = complex<double>;
template<typename T> inline void priv(vector<T>a){REP(i,a.size()){cerr<<a[i]<<((i==a.size()-1)?"\n":" ");}}
ll gcd(ll a,ll b){int c=max(a,b);int d=min(a,b);return c==0||d==0?c:gcd(c%d,d);}
ll lcm(ll a,ll b){return a==0||b==0?0:a*b/gcd(a,b);}
ll fact(ll a){ll b=1;for(ll i=1;i<=a;i++)b*=i;return b;}
ll power(ll x,ll n){ll a=1;REP(i,n)a*=x;return a;}
double inf() {return std::numeric_limits<double>::infinity();}

string s;
ll x, y;
ll off = 20005;
ll N = 10000;
int dp[40010], dpx[40010], dpy[40010];

int main(int argc, char const *argv[]) {
  cin >> s;
  cin >> x >> y;
  vector<ll> lx, ly;
  ll d = 0, l = 0;
  REP(i,s.size()) {
    if(s[i]=='F') l++;
    else {
      if(d%2==0) lx.push_back(l);
      else ly.push_back(l);
      l = 0;
      d++;
    }
  }
  if(d%2==0) lx.push_back(l);
  else ly.push_back(l);
  // priv(lx);
  // priv(ly);
  if(lx.size() > 0) dpx[off+lx[0]]=true;
  FOR(i,1,lx.size()) {
    UP(j,off-N,off+N) dp[j] = dpx[j-lx[i]] | dpx[j+lx[i]];
    UP(j,off-N,off+N) dpx[j] = dp[j];
  }
  dpy[off]=1;
  FOR(i,0,ly.size()) {
    UP(j,off-N,off+N) dp[j] = dpy[j-ly[i]] | dpy[j+ly[i]];
    UP(j,off-N,off+N) dpy[j] = dp[j];
  }
  // REP(i,10) cerr<<dpx[off-i]<<((i==9?"\n":" "));
  // REP(i,10) cerr<<dpx[off+i]<<((i==9?"\n":" "));
  // REP(i,10) cerr<<dpy[off-i]<<((i==9?"\n":" "));
  // REP(i,10) cerr<<dpy[off+i]<<((i==9?"\n":" "));
  if(dpx[off+x] && dpy[off+y]) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
