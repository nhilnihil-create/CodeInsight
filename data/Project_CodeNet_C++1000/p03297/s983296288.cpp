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

bool solve(){
  ll A,B,C,D;cin >> A >> B >> C >> D;
  if(A<B)return false;
  if(D<B) return false;
  if(B<=C) return true;
  //C<B && B<=Dとなっている
  A%=B;
  if(A>C)return false;
  D%=B;
  if(D==0)return true;
  set<ll> st;
  while(true){
    A%=B;
    A%=D;
    if(st.count(A))return true;
    st.insert(A);
    ll Q = (B-A-1)/D;
    A+=Q*D;
    if(A>C)break;
    A+=D;
  }
  return false;
}

int main(void){
  SPEEDUP
  cout << setprecision(15);
  int T;cin >> T;
  while(T--){
    YesNo(solve());
  }
  return 0;
} 

//1回の補充で増える数D
