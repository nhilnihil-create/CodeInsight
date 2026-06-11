#include <bits/stdc++.h>
#define pt(sth) cout << sth << "\n"
#define chmax(a, b) {if(a<b) a=b;}
#define chmin(a, b) {if(a>b) a=b;}
#define moC(a, s, b) (a)=((a)s(b)+MOD)%MOD
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
static const ll INF=1e18;
static const ll MAX=101010;
static const ll MOD=1e9+7;


ll gcd(ll a, ll b) {
  if(b==0) return a;
  else return gcd(b, a%b);
}

int main(void) {
  ll N, M;
  cin >> N >> M;
  string s, t;
  cin >> s >> t;
  
  ll L=N*M/gcd(N, M);
  ll l=L/N*L/M*gcd(L/N, L/M);
  
  ll f=1;
  for(ll k=0; k<=L/l; k++) {
    if(s[k*N*l/L]!=t[k*M*l/L]) f=0;
  }
  
  if(f) pt(L);
  else pt(-1);
  
  
}


