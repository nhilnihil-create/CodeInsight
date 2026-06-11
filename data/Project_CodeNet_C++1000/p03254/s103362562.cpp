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
  ll N, X;
  cin>>N>>X;
  vector<ll> A(N);
  for(int i=0;i<N;++i) cin>>A[i];
  sort(A.begin(), A.end());
  ll sum = X;
  int ans;
  for(int i=0;i<N;++i) {
    if(i==N-1) {
      if(sum==A[i]) ans = N;
      else ans = N-1;
    }
    else {
      if(sum<A[i]) {
        ans = i;
        break;
      }
    }
    sum -= A[i];
  }
  cout<<ans<<endl;
}

