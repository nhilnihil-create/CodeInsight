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

int ANS(string ans){
  if(ans == "Male") return 1;
  else if(ans == "Female") return -1;
  else return 0;
}

int solve(){
  int N;cin >> N;
  string ans;
  int l = 0, r = N-1;
  int la,ma,ra;
  printf("%d\n",l);
  fflush(stdout);
  cin >> ans;
  la = ANS(ans);
  if(la == 0)return 0;

  printf("%d\n",r);
  fflush(stdout);
  cin >> ans;
  ra = ANS(ans);
  if(ra == 0)return 0;

  while(r-l>1){
    int m = (r+l)/2;
    printf("%d\n",m);
    fflush(stdout);
    cin >> ans;
    ma = ANS(ans);
    if(ma==0) return 0;

    if((l-m)%2 == 0){
      if(la == ma){
        la = ma;
        l = m;
      }else{
        ra = ma;
        r = m;
      }
    }else{
      if(la == ma){
        ra = ma;
        r = m;
      }else{
        la = ma;
        l = m;
      }
    }
  }

  return 1;
}

int main(void){
  SPEEDUP
  cout << setprecision(15);
  solve();
  return 0;
}
