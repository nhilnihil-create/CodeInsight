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


int main(){
  int n; cin >> n; int san, ni;
  if(n==3){
    cout << "2 5 63" << endl; return 0;
  }
  rep(i, min(5001, n-1)){
    if(i==0) continue;
    if(i%2==0 && ((n-i)%3==2 || (n-i)%3==0)){
      san = i;
    }
  }
  ni = n - san;
  rep(i, san){
    cout << 3+6*i; cout << " ";
  }
  rep(i, ni){
    cout << 2*(i+1); if(i!=(ni-1)) cout << " ";
  }
  cout << endl;
}