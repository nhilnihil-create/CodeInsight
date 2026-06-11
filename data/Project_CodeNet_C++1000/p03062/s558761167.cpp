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
  ll N;
  cin>>N;
  ll A[N];
  for(int i=0;i<N;++i) cin>>A[i];
  int num = 0;
  for(int i=0;i<N;++i) {
    if(A[i]<0) num++;
  }
  ll ans = 0;
  if(num%2==0) {
    for(int i=0;i<N;++i) {
    ans += abs(A[i]);
    }
  }
  else {
    ll num = inf;
    for(int i=0;i<N;++i) {
      num = min(num, abs(A[i]));
    }
    for(int i=0;i<N;++i) {
      ans += abs(A[i]);
    }
    ans -= 2*num;
  }
  cout<<ans<<endl;
}

