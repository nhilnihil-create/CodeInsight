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
  int N, M, C;
  cin>>N>>M>>C;
  int ans = 0;
  int sum;
  int tmp;
  int B[M];
  for(int i=0;i<M;++i) cin>>B[i];
  for(int i=0;i<N;++i) {
    sum = C;
    for(int j=0;j<M;++j) {
      cin>>tmp;
      sum += B[j]*tmp;
    }
    if(sum>0) ans++;
  }
  cout<<ans<<endl;
}

