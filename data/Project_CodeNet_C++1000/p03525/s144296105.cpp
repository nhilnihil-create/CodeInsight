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

int dfs(int cur,vector<int>& x){
  if(cur==12){
    vector<int> ans;
    rep(i,24){
      if(x[i] == 1)ans.push_back(i);
    }
    int d = ans[0] + 24 - ans[ans.size()-1];
    int ret = min(d,24-d);
    repp(i,1,ans.size()){
      d = ans[i] - ans[i-1];
      ret = min({ret,d,24-d});
    }
    return ret;
  }

  if(x[cur] !=-1) return dfs(cur+1,x);
  x[cur] = 1;
  x[24-cur] = 0;
  int ret = dfs(cur+1,x);
  x[cur] = 0;
  x[24-cur] = 1;
  ret = max(ret,dfs(cur+1,x));
  x[cur] = -1;
  x[24-cur] = -1;
  return ret;
}

int solve(){
  int N;cin >> N;
  vector<int> v(N);
  vector<int> w(13);
  rep(i,N){
    cin >> v[i];
    ++w[v[i]];
  }
  //-1は未定
  vector<int> x(24,-1);
  if(w[0] > 0)return 0;
  x[0] = 1;
  if(w[12] > 1) return 0;
  if(w[12] == 1) x[12] = 1;
  else x[12] = 0;
  repp(i,1,12){
    if(w[i]>2) return 0;
    if(w[i] == 2){
      x[i] = 1;
      x[24-i] = 1;
    }
    if(w[i] == 0){
      x[i] = 0;
      x[24-i] = 0;
    }
  }
  return dfs(1,x);
}

int main(void){
  SPEEDUP
  cout << setprecision(15);
  cout << solve() << endl;

  return 0;
}
