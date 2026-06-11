#include<iostream>
#include <cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
using namespace std;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
using ll = long long;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;


int main(){
  string S; cin >> S;
  int N = S.size();
  ll cnta=0, cntab=0, cntabc=0, cnthatena=1;
  rep(i, N){
    if(S[i]=='A') cnta+=cnthatena; cnta%=mod;
    if(S[i]=='B') cntab+=cnta; cntab%=mod;
    if(S[i]=='C') cntabc+=cntab; cntabc%=mod;
    if(S[i]=='?'){
      cntabc*=3; cntabc%=mod; cntabc+=cntab; cntabc%=mod;
      cntab*=3; cntab%=mod; cntab+=cnta; cntab%=mod;
      cnta*=3; cnta%=mod; cnta+=cnthatena; cnta%=mod;
      cnthatena*=3; cnthatena%=mod;
      }
    }
  cout << cntabc << endl;
}