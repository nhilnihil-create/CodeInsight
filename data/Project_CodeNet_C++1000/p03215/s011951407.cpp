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
  ll A[N+1];
  A[0] = 0;
  for(ll i=1;i<=N;++i) cin>>A[i];
  for(ll i=1;i<=N;++i) A[i] += A[i-1];
  vector<ll> arr;
  for(ll i=0;i<=N;++i) {
    for(ll j=i+1;j<=N;++j) {
      arr.push_back(A[j]-A[i]);
    }
  }
  vector<ll> newarr;
  for(ll i=42;i>=0;--i) {
    newarr.clear();
    for(ll j=0;j<arr.size();++j) {
      if((arr[j]&(1ull<<i))!=0) newarr.push_back(arr[j]);
    }
    if(newarr.size()>=K) arr = newarr;
  }
  ll ans = arr[0];
  for(ll i=1;i<K;++i) ans &= arr[i];
  cout<<ans<<endl;
}
