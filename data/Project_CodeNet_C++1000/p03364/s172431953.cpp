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
typedef pair<int,int> P;
typedef long long ll;
typedef long double ld;
const int inf=1e9+7;
const ll longinf=1LL<<60;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define F first
#define S second

const int mx=200010;
const ll mod=1e9+7;


int main(){
  int n;
  cin >> n;
  string a[n];
  rep(i,n){
    string s; cin >> s;
    a[i] = s+s;
  }
  ll ans = 0;
  rep(i,n){
    bool flag = true;
    rep(j,n)rep(k,n){
      if(a[j][k+i] != a[k][j+i]){
        flag = false;
      }
    }
    if(flag){
      ans += n;
    }
  }
  cout << ans << endl;
  return 0;
}
