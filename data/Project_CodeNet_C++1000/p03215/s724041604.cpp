#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0,i##_max=(N);i<i##_max;++i)
#define repp(i,l,r) for(int i=(l),i##_max=(r);i<i##_max;++i)
#define per(i,N) for(int i=(N)-1;i>=0;--i)
#define perr(i,l,r) for(int i=r-1,i##_min(l);i>=i##_min;--i)
#define all(arr) (arr).begin(), (arr).end()
#define SP << " " <<
#define SPF << " "
#define SPEEDUP cin.tie(0);ios::sync_with_stdio(false);
#define MAX_I INT_MAX //1e9
#define MIN_I INT_MIN //-1e9
#define MAX_UI UINT_MAX //1e9
#define MAX_LL LLONG_MAX //1e18
#define MIN_LL LLONG_MIN //-1e18
#define MAX_ULL ULLONG_MAX //1e19
  typedef long long ll;
  typedef pair<int,int> PII;
  typedef pair<char,char> PCC;
  typedef pair<ll,ll> PLL;
  typedef pair<char,int> PCI;
  typedef pair<int,char> PIC;
  typedef pair<ll,int> PLI;
  typedef pair<int,ll> PIL; 
  typedef pair<ll,char> PLC; 
  typedef pair<char,ll> PCL; 

inline void YesNo(bool b){ cout << (b?"Yes" : "No") << endl;}
inline void YESNO(bool b){ cout << (b?"YES" : "NO") << endl;}
inline void Yay(bool b){ cout << (b?"Yay!" : ":(") << endl;}

int main(void){
  SPEEDUP
  cout << setprecision(15);
  int N,K;cin >> N >> K;
  vector<ll> v(N+1,0);
  rep(i,N)cin >> v[i+1];
  rep(i,N) v[i+1] += v[i];

  map<ll,int> mp;
  rep(i,N) repp(j,i+1,N+1) ++mp[v[j] - v[i]];
  int M = 0;
  vector<PLI> w(mp.size());
  for(const PLI m : mp) w[M++] = m;
  ll x = 0;
  vector<bool> prv(M,true);
  int n_2 = 0;
  while((1ll<<n_2) <= v[N]) ++n_2;
  per(n,n_2){
    int count = 0;
    ll n_ = 1ll<<n;
    vector<bool> nxt(M,false);
    rep(i,M){
      if(!prv[i])continue;
      if(w[i].first&n_){
        count+=w[i].second;
        nxt[i] = true;
      }
    }
    if(count >= K){
      swap(prv,nxt);
      x |= n_;
    }
  }
  cout << x << endl;
  return 0;
}

