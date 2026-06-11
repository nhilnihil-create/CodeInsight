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
const ll big=1e18;
const double PI=2*asin(1);

int main() {
  ll N, M;
  cin>>N>>M;
  ll A[N+1];
  A[0] = 0;
  for(int i=1;i<=N;++i) {
    cin>>A[i];
  }
  for(int i=1;i<=N;++i) {
    A[i] += A[i-1];
    A[i] %= M;
  }
  map<ll, ll> amap;
  vector<ll> arr;
  for(int i=0;i<=N;++i) {
    if(amap[A[i]]==0) arr.push_back(A[i]);
    amap[A[i]]++;
  }
  ll ans = 0;
  for(int i=0;i<arr.size();++i) {
    ans += amap[arr[i]]*(amap[arr[i]]-1)/2;
  }
  cout<<ans<<endl;
}
