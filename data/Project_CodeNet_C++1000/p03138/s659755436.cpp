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
  ll N, K;
  cin>>N>>K;
  ll A[N];
  for(int i=0;i<N;++i) cin>>A[i];
  ll ans = 0;
  ll tmp;
  for(int i=42;i>=0;--i) {
    if(ans+(1ull<<i)>K) continue;
    tmp = 0;
    for(int j=0;j<N;++j) {
      if((A[j]&(1ull<<i))==0) tmp++;
    }
    if(tmp*2>N) ans += (1ull<<i);
  }
  ll ans1 = 0;
  for(int i=0;i<N;++i) {
    ans1 += A[i]^ans;
  }
  cout<<ans1<<endl;
}

