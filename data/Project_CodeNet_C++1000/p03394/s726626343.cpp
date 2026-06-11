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

set<int> eratosthenes(int n){
  set<int> st;
  st.insert(2);
  for(int i = 3; i<=n ;i+=2) st.insert(i);
  for(auto it = st.begin(); it != st.end(); ++it){
    auto it2 = it;
    ++it2;
    for(; it2 != st.end(); ++it2){
      if((*it2)%(*it)==0){
        auto it3 = it2;
        --it3;
        st.erase(it2);
        it2 = it3;
      }
    }
  }
  return st;
}

int solve(){
  int N;cin >> N;
  if(N==3){
    cout << 2 SP 3 SP 25 << endl;
    return 0;
  }else if(N==4){
    cout << 2 SP 3 SP 5 SP 20 << endl;
    return 0;
  }else if(N==5){
    cout << 2 SP 3 SP 5 SP 6 SP 14 << endl;
    return 0;
  }
  set<int> st;
  st.insert(2);
  st.insert(3);
  N-=2;
  int x = 4;
  int sum = 5;
  rep(i,N){
    while((x%2)&&(x%3))++x;
    sum+=x;
    st.insert(x);
    ++x;
  }
  --x;
  if(sum%6==2){
    st.erase(8);
    st.insert(6*((x+6)/6));
  }else if(sum%6==3){
    st.erase(9);
    st.insert(6*((x+6)/6));
  }else if(sum%6==5){
    st.erase(9);
    st.insert(6*(x/6)+4);
  }

  for(const int &s : st)cout << s SPF;
  cout << endl;
  return 0;
}

int main(void){
  SPEEDUP
  cout << setprecision(15);
  solve();
  return 0;
}

