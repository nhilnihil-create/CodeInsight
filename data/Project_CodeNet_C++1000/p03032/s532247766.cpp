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
  int N, K;
  cin>>N>>K;
  ll V[N];
  for(int i=0;i<N;++i) cin>>V[i];
  vector<ll> jewel;
  ll ans = -big;
  ll tmpans;
  for(int l=0;l<=N;++l) {
    for(int r=0;r+l<=N;++r) {
      if(l+r>K) continue;
      jewel.clear();
      for(int k=0;k<l;++k) jewel.push_back(V[k]);
      for(int k=0;k<r;++k) jewel.push_back(V[N-1-k]);
      sort(jewel.begin(), jewel.end());
      tmpans = 0;
      for(int k=0;k<l+r;++k) {
        if(K-(l+r)>k && jewel[k]<0) continue;
        tmpans += jewel[k];
      }
      ans = max(ans, tmpans);
    }
  }
  cout<<ans<<endl;
}

