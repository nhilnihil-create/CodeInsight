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
  ll N,A,B;cin >> N >> A >> B;
  if(A+B-1 > N || A*B < N){
    cout << -1 << endl;
    return 0;
  }
  vector<ll> v(N);
  int s = B;
  rep(i,N){
    ll x = i%A;
    ll y = i/A;
    v[i] = B-y + B*x;
    if(x==0)--s;
  }

  for(int i = 0; i<s ; ++i){
    if(v[N-1-i] == s+1)++s;
    v[N-1-i] = i+1;
  }

  map<ll,int> mp;
  rep(i,N) mp[v[i]] = 0;
  s = 0;
  for(auto & m : mp) m.second = ++s;
  rep(i,N)  cout << mp[v[i]] SPF;
  cout << endl;
  return 0;
}
