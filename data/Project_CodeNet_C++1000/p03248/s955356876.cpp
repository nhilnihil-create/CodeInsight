#include<iostream>
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
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;
#define pai 3.141592653589793238462643383279




int main(){
  string S; cin >> S; int N = S.size();
  if(S[0]=='0'){
    cout << -1 << endl; return 0;
  }
  if(S[N-1]=='1'){
    cout << -1 << endl; return 0;
  }
  rep(i, N-1){
    if(S[i]!=S[N-2-i]){
      cout << -1 << endl; return 0;
    }
  }
  vector<int> ichi;
  rep(i, N){
    if(S[i]=='1') ichi.push_back(i+1);
  }
  rep(i, ichi.size()){
    if(i==0) continue;
    for(int j=ichi[i-1]; j<ichi[i]; j++){
      cout << j << " " << ichi[i] << endl;
    }
  }
  cout << N-1 << " " << N << endl;
}
