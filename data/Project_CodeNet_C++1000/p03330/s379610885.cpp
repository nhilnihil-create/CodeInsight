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
#define mt make_tuple
#define pqueue priority_queue
const int inf=1e9+7;
const ll mod=1e9+7;
const ll mod1=998244353;
const ll big=1e18;
const double PI=2*asin(1);

int main() {
  int N, C;
  cin>>N>>C;
  int D[C][C];
  for(int i=0;i<C;++i) {
    for(int j=0;j<C;++j) {
      cin>>D[i][j];
    }
  }
  int c[N][N];
  for(int i=0;i<N;++i) {
    for(int j=0;j<N;++j) {
      cin>>c[i][j];
      c[i][j]--;
    }
  }
  int color[3][C];
  for(int i=0;i<3;++i) {
    for(int j=0;j<C;++j) {
      color[i][j] = 0;
    }
  }
  for(int i=0;i<N;++i) {
    for(int j=0;j<N;++j) {
      color[(i+j)%3][c[i][j]]++;
    }
  }
  int ans=inf;
  int tmp;
  for(int i=0;i<C;++i) {
    for(int j=0;j<C;++j) {
      if(i==j) continue;
      for(int k=0;k<C;++k) {
        if(i==k || j==k) continue;
        tmp = 0;
        for(int l=0;l<C;++l) {
          tmp += color[0][l]*D[l][i];
        }
        for(int l=0;l<C;++l) {
          tmp += color[1][l]*D[l][j];
        }
        for(int l=0;l<C;++l) {
          tmp += color[2][l]*D[l][k];
        }
        ans = min(ans, tmp);
      }
    }
  }
  cout<<ans<<endl;
}

