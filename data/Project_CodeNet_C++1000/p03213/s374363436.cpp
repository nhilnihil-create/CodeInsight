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
  map<int, int> amap;
  int tmp;
  for(int i=2;i<=N;++i) {
    tmp = i;
    for(int j=2;j*j<=tmp;++j) {
      if(tmp%j==0) {
        while(tmp%j==0) {
          amap[j]++;
          tmp /= j;
        }
      }
    }
    if(tmp>1) amap[tmp]++;
  }
  int A=0, B=0, C=0, D=0, E=0, F=0, G=0, H=0;
  for(int i=0;i<=N;++i) {
    if(amap[i]>=2 && amap[i]<4) A++;
    if(amap[i]>=4) B++;
    if(amap[i]>=4 && amap[i]<14) C++;
    if(amap[i]>=14) D++;
    if(amap[i]>=2 && amap[i]<24) E++;
    if(amap[i]>=24) F++;
    if(amap[i]>=74) H++;
  }
  int ans = 0;
  ans += max(0, A*B*(B-1)/2)+max(0, B*(B-1)*(B-2)/2);
  ans += C*D+D*(D-1);
  ans += E*F+F*(F-1);
  ans += H;
  cout<<ans<<endl;
}
