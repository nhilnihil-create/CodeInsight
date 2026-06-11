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
  int N;cin >> N;
  vector<int> v(N);
  int ma = MIN_I;
  int ma_i = 0;
  int mi = MAX_I;
  int mi_i = 0;
  rep(i,N){
    cin >> v[i];
    if(v[i] > ma){
      ma = v[i];
      ma_i = i;
    }
    if(v[i] < mi){
      mi = v[i];
      mi_i = i;
    }
  }
  queue<PII> que;
  if(ma > -mi){
    rep(i,N) if(v[i] < 0){
      que.push(PII(ma_i,i));
      v[i] += ma;
    }
    rep(i,N-1){
      if(v[i+1] < v[i]){
        que.push(PII(i,i+1));
        v[i+1] += v[i];
      }
    }
  }else{
    rep(i,N) if(v[i]>0){
      que.push(PII(mi_i,i));
      v[i] += mi;
    }
    per(i,N-1){
      if(v[i+1] < v[i]){
        que.push(PII(i+1,i));
        v[i] += v[i+1];
      }
    }
  }
  cout << que.size() << endl;
  while(!que.empty()){
    cout << que.front().first+1 SP que.front().second+1 << endl;
    que.pop();
  }
  return 0;
}
