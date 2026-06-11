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
  typedef pair<double,double> PDD;

inline void YesNo(bool b){ cout << (b?"Yes" : "No") << endl;}
inline void YESNO(bool b){ cout << (b?"YES" : "NO") << endl;}
inline void Yay(bool b){ cout << (b?"Yay!" : ":(") << endl;}

const double MAX_V = 100.5;

int main(void){
  SPEEDUP
  cout << setprecision(15);
  int N;cin >> N;
  vector<double> t(N);
  vector<double> t_(N+1);
  vector<double> v(N);
  rep(i,N) cin >> t[i];
  rep(i,N) cin >> v[i];
  t_[0] = 0.0;
  rep(i,N) t_[i+1] = t_[i]+t[i];
  double T = t_[N];
  double time = 0.0;
  vector<double> w((int)T*2+1);
  while(time <= T){
    double v_ = MAX_V;
    v_ = min(v_,time);
    v_ = min(v_,T-time);
    rep(i,N){
      if(time <= t_[i]) v_ = min(v_, v[i] + t_[i] - time);
      else if(time <=t_[i+1]) v_ = min(v_, v[i]);
      else v_ = min(v_, v[i] + time -t_[i+1]);
    }
    int index =  (int)2*time;
    w[index] = v_;
    time+=0.5;
  }
  double ans = 0.0;
  rep(i,w.size()-1) ans += 0.25*(w[i]+w[i+1]);
  cout << ans << endl;
  return 0;
}
