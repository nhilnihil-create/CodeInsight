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
  ll N, K;
  cin>>N>>K;
  ll A[N];
  for(int i=0;i<N;++i) cin>>A[i];

  ll flag;
  ll ans = 0;
  for(ll i=42;i>=0;--i) {
    flag = 0;
    for(int j=0;j<N;++j) {
      if((A[j]&(1ull<<i))!=0) flag++;
    }
    if(flag<N-flag && K>=(1ull<<i)) {
      K -= (1ull<<i);
      flag = N-flag;
    }
    ans += flag*(1ull<<i);
  }
  cout<<ans<<endl;
}

