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
  int N, M;
  cin>>N>>M;
  ll x[N], y[N], z[N];
  for(int i=0;i<N;++i) cin>>x[i]>>y[i]>>z[i];
  vector<ll> arr(N);
  ll ans = 0;
  ll tmp;
  for(int i=0;i<N;++i) {
    arr[i] = x[i]+y[i]+z[i];
  }
  sort(arr.begin(), arr.end(), greater<ll>());
  tmp = 0;
  for(int i=0;i<M;++i) tmp += arr[i];
  ans = max(ans, tmp);
  for(int i=0;i<N;++i) {
    arr[i] = -x[i]+y[i]+z[i];
  }
  sort(arr.begin(), arr.end(), greater<ll>());
  tmp = 0;
  for(int i=0;i<M;++i) tmp += arr[i];
  ans = max(ans, tmp);
  for(int i=0;i<N;++i) {
    arr[i] = x[i]-y[i]+z[i];
  }
  sort(arr.begin(), arr.end(), greater<ll>());
  tmp = 0;
  for(int i=0;i<M;++i) tmp += arr[i];
  ans = max(ans, tmp);
  for(int i=0;i<N;++i) {
    arr[i] = x[i]+y[i]-z[i];
  }
  sort(arr.begin(), arr.end(), greater<ll>());
  tmp = 0;
  for(int i=0;i<M;++i) tmp += arr[i];
  ans = max(ans, tmp);
  for(int i=0;i<N;++i) {
    arr[i] = -x[i]-y[i]+z[i];
  }
  sort(arr.begin(), arr.end(), greater<ll>());
  tmp = 0;
  for(int i=0;i<M;++i) tmp += arr[i];
  ans = max(ans, tmp);
  for(int i=0;i<N;++i) {
    arr[i] = -x[i]+y[i]-z[i];
  }
  sort(arr.begin(), arr.end(), greater<ll>());
  tmp = 0;
  for(int i=0;i<M;++i) tmp += arr[i];
  ans = max(ans, tmp);
  for(int i=0;i<N;++i) {
    arr[i] = x[i]-y[i]-z[i];
  }
  sort(arr.begin(), arr.end(), greater<ll>());
  tmp = 0;
  for(int i=0;i<M;++i) tmp += arr[i];
  ans = max(ans, tmp);
  for(int i=0;i<N;++i) {
    arr[i] = -x[i]-y[i]-z[i];
  }
  sort(arr.begin(), arr.end(), greater<ll>());
  tmp = 0;
  for(int i=0;i<M;++i) tmp += arr[i];
  ans = max(ans, tmp);
  cout<<ans<<endl;
}

