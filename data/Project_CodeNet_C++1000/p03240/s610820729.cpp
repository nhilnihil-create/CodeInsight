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
  int N;
  cin>>N;
  int x[N], y[N], h[N];
  for(int i=0;i<N;++i) cin>>x[i]>>y[i]>>h[i];
  int index;
  for(int i=0;i<N;++i) {
    if(h[i]>0) {
      index = i;
      break;
    }
  }
  bool ok;
  int height;
  int tmp;
  int Cx, Cy, H;
  for(int i=0;i<=100;++i) {
    for(int j=0;j<=100;++j) {
      height = h[index] + abs(x[index]-i) + abs(y[index]-j);
      ok = true;
      for(int k=0;k<N;++k) {
        tmp = max(0, height-abs(x[k]-i)-abs(y[k]-j));
        if(tmp!=h[k]) ok = false;
      }
      if(ok) {
        Cx = i;
        Cy = j;
        H = height;
      }
    }
  }
  cout<<Cx<<" "<<Cy<<" "<<H<<endl;
}

