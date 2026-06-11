#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<vector>
#include<list>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
#define rep(i, n) for(int i=0;i<n;++i)
#define rrep(i, n) for(int i=n;i>=0;--i)
const int inf=1e9+7;
const ll mod=1e9+7;
const ll big=1e18;
const double PI=2*asin(1);

int main() {
  int N;
  cin>>N;
  vector<string> S(N);
  for(int i=0;i<N;++i) cin>>S[i];
  int ans = 0;
  bool ok;
  for(int i=0;i<N;++i) {
    ok = true;
    for(int j=0;j<N;++j) {
      for(int k=0;k<N;++k) {
        if(S[(j+i)%N][k]!=S[(k+i)%N][j]) ok = false;
      }
    }
    if(ok) ans += N;
  }
  cout<<ans<<endl;
}

