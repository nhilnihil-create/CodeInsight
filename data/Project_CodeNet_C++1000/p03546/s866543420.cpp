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
  int H, W;
  cin>>H>>W;
  int C[10][10];
  for(int i=0;i<10;++i) {
    for(int j=0;j<10;++j) {
      cin>>C[i][j];
    }
  }
  for(int k=0;k<10;++k) {
    for(int i=0;i<10;++i) {
      for(int j=0;j<10;++j) {
        C[i][j] = min(C[i][j], C[i][k]+C[k][j]);
      }
    }
  }
  int ans = 0;
  int tmp;
  for(int i=0;i<H;++i) {
    for(int j=0;j<W;++j) {
      cin>>tmp;
      if(tmp>-1) ans += C[tmp][1];
    }
  }
  cout<<ans<<endl;
}

