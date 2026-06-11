#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
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
const ll mod1=998244353;
const ll big=1e18;
const double PI=2*asin(1);

int main() {
  int N, C;
  cin>>N>>C;
  int D[C][C], c[N][N];
  for(int i=0;i<C;++i) {
    for(int j=0;j<C;++j) {
      cin>>D[i][j];
    }
  }
  for(int i=0;i<N;++i) {
    for(int j=0;j<N;++j) {
      cin>>c[i][j];
      c[i][j]--;
    }
  }
  int ans[3][C];
  for(int i=0;i<3;++i) {
    for(int j=0;j<C;++j) {
      ans[i][j] = 0;
    }
  }
  for(int i=0;i<N;++i) {
    for(int j=0;j<N;++j) {
      for(int k=0;k<C;++k) {
        ans[(i+j)%3][k] += D[c[i][j]][k];
      }
    }
  }
  int ans1 = inf;
  for(int i=0;i<C;++i) {
    for(int j=0;j<C;++j) {
      if(i==j) continue;
      for(int k=0;k<C;++k) {
        if(j==k || k==i) continue;
        ans1 = min(ans1, ans[0][i]+ans[1][j]+ans[2][k]);
      }
    }
  }
  cout<<ans1<<endl;
}
