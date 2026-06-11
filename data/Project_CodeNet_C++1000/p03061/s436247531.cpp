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

ll gcd(ll a, ll b) {
  ll v0=a, v1=b, v2=v0%v1;
  while(v2>0) {
    v0 = v1;
    v1 = v2;
    v2 = v0%v1;
  }
  return v1;
}

int main() {
  int N;
  cin>>N;
  ll A[N];
  for(int i=0;i<N;++i) cin>>A[i];
  ll gcds1[N], gcds2[N];
  gcds1[0] = A[0];
  for(int i=1;i<N;++i) {
    gcds1[i] = gcd(gcds1[i-1], A[i]);
  }
  gcds2[N-1] = A[N-1];
  for(int i=N-2;i>=0;--i) {
    gcds2[i] = gcd(gcds2[i+1], A[i]);
  }
  ll ans = 1;
  /**
  for(int i=0;i<N;++i) cout<<gcds1[i]<<" ";
  cout<<endl;
  for(int i=0;i<N;++i) cout<<gcds2[i]<<" ";
  cout<<endl;
  **/
  for(int i=0;i<N;++i) {
    if(i==0) ans = max(ans, gcds2[1]);
    else if(i==N-1) ans = max(ans, gcds1[N-2]);
    else ans = max(ans, gcd(gcds1[i-1], gcds2[i+1]));
  }
  cout<<ans<<endl;
}

