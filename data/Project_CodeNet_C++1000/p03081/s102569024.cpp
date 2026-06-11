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

string s;
vector<PCC> v;
int N,Q;
int move(int pos){
  rep(i,Q){
    if(s[pos] == v[i].first){
      if(v[i].second=='L')--pos;
      else ++pos;
    }
  }
  return pos;
}


int main(void){
  SPEEDUP
  cout << setprecision(15);
  cin >> N >> Q;
  cin >> s;
  s = " " + s + " ";
  v.resize(Q);
  rep(i,Q)cin >> v[i].first >> v[i].second;
  //左に落ちる最大の位置
  int ls = 0,le = N+1;
  while(le-ls>1){
    int lm = (ls+le)/2;
    if(move(lm) == 0) ls = lm;
    else le = lm;
  }

  //右に落ちる最小の位置
  int rs = 0,re = N+1;
  while(re-rs>1){
    int rm = (rs+re)/2;
    if(move(rm) == N+1) re = rm;
    else rs = rm;
  }
  cout << N - ls - (N+1-re) << endl;
  return 0;
}
