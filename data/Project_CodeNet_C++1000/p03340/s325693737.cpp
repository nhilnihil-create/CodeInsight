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
  int N; cin >> N; int a[N];
  rep(i, N){
    cin >> a[i];
  }
  int left = 0, right = 0, bits=0; ll ans = 0;
  rep(left, N){
    while(right<N && (bits^a[right])==(bits+a[right])){
      bits^=a[right]; right++;
    }
    ans+=right-left;
    if(right==left) right++;
    else bits^=a[left];
  }
  cout << ans << endl;
}