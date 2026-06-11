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

const int K_MAX = 1e5+5;
bool reached[K_MAX];

int solve(){
  int K;cin >> K;
  deque<PII> dq(1,PII(1,1));
  reached[1] = true;
  int n,count,val1,val2;
  while(!dq.empty()){
    //cout << dq.front().first SP dq.front().second << endl;
    n = dq.front().first;
    count = dq.front().second;
    if(n == 0) return count;
    reached[n] = true;
    val1 = (n+1)%K;
    val2 = (n*10)%K;
    dq.pop_front();
    if(!reached[val1]) dq.push_back(PII(val1,count+1));
    if(!reached[val2]) dq.push_front(PII(val2,count));
  }
  return 0;
}

int main(void){
  SPEEDUP
  cout << setprecision(15);
  cout << solve() << endl;
  return 0;
}


