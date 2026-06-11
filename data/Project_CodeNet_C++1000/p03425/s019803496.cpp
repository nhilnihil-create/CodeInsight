/**
*    author:  yuya1234
*    created: 13.07.2020 16:42:02
**/

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)
#define FORV(i,v) for(auto i=v.begin(); i!=v.end();i++)

#define SORT(s) sort((s).begin(),(s).end())
#define SORTD(s) sort((s).rbegin(),(s).rend())
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );

#define SZ(x) ((int)(x).size())
#define MEMSET(v, h) memset((v), h, sizeof(v))

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
int gcd(int a,int b){return b?gcd(b,a%b):a;}

template< typename T >
struct Combination {
  vector< T > _fact, _rfact, _inv;

  Combination(int sz) : _fact(sz + 1), _rfact(sz + 1), _inv(sz + 1) {
    _fact[0] = _rfact[sz] = _inv[0] = 1;
    for(int i = 1; i <= sz; i++) _fact[i] = _fact[i - 1] * i;
    _rfact[sz] /= _fact[sz];
    for(int i = sz - 1; i >= 0; i--) _rfact[i] = _rfact[i + 1] * (i + 1);
    for(int i = 1; i <= sz; i++) _inv[i] = _rfact[i] * _fact[i - 1];
  }

  inline T fact(int k) const { return _fact[k]; }

  inline T rfact(int k) const { return _rfact[k]; }

  inline T inv(int k) const { return _inv[k]; }

  T P(int n, int r) const {
    if(r < 0 || n < r) return 0;
    return fact(n) * rfact(n - r);
  }

  T C(int p, int q) const {
    if(q < 0 || p < q) return 0;
    return fact(p) * rfact(q) * rfact(p - q);
  }

  T H(int n, int r) const {
    if(n < 0 || r < 0) return (0);
    return r == 0 ? 1 : C(n + r - 1, r);
  }
};

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  //std::cout << std::fixed << std::setprecision(15);

  int n;
  cin>>n;

  string s[n];
  ll cnt[5];
  MEMSET(cnt,0);
  REP(i,n){
    cin>>s[i];
    if(s[i][0]=='M')cnt[0]++;
    else if(s[i][0]=='A')cnt[1]++;
    else if(s[i][0]=='R')cnt[2]++;
    else if(s[i][0]=='C')cnt[3]++;
    else if(s[i][0]=='H')cnt[4]++;
  }

  ll ans=0;
  REP(i,5)FOR(j,i+1,4)FOR(k,j+1,4){
    ans+=cnt[i]*cnt[j]*cnt[k];
  }

  cout<<ans<<endl;



  return 0;
}