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
  string S;cin >> S;
  int N = S.length();
  bool Impossible = false;
  if(S[N-1] == '1') Impossible = true;
  if(S[0] == '0')Impossible = true;
  rep(i,N/2) if(S[i] != S[N-2-i])Impossible = true;
  if(Impossible){
    cout << -1 << endl;
    return 0;
  }
  int l = 1,r = 1;
  int next1 = 2, next2 = 3;
  if(N%2==0){
    if(S[N/2-1] == '1'){
      cout << l SP next1 << endl;
      r = next1;
      next1+=2;
    }else{
      cout << l SP next1 << endl;
      next1+=2;
    }
    --N;
  }

  per(i,N/2){
    if(S[i] == '1'){
      cout << l SP next1 << endl;
      cout << r SP next2 << endl;
      l = next1;
      r = next2;
      next1+=2;
      next2+=2;
    }else{
      cout << l SP next1 << endl;
      cout << r SP next2 << endl;
      next1+=2;
      next2+=2;
    }
  }
  return 0;
}
