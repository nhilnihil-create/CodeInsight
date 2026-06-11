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

ll gcd(ll a, ll b) {
  ll v0 = a, v1 = b, v2 = v0%v1;
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
  ll ans = gcd(A[0], A[1]);
  for(int i=2;i<N;++i) ans = gcd(ans, A[i]);
  cout<<ans<<endl;
}

