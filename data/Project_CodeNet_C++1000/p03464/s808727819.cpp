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
  ll K;
  cin>>K;
  ll A[K];
  for(ll i=0;i<K;++i) cin>>A[i];
  ll mini[K+1], maxi[K+1];
  mini[K] = 2;
  maxi[K] = 2;
  bool ok = true;
  for(ll i=K-1;i>=0;--i) {
    mini[i] = mini[i+1] + (A[i]-mini[i+1]%A[i])%A[i];
    if(mini[i]>maxi[i+1]) ok = false;
    maxi[i] = maxi[i+1]/A[i]*A[i]+A[i]-1;
  }
  /**
  for(ll i=0;i<=K;++i) cout<<mini[i]<<" ";
  cout<<endl;
  for(ll i=0;i<=K;++i) cout<<maxi[i]<<" ";
  cout<<endl;
  **/
  if(ok) {
    cout<<mini[0]<<" "<<maxi[0]<<endl;
  }
  else cout<<-1<<endl;
}
