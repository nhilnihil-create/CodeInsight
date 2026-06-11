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

ll parent[100005];
ll siz[100005];

ll root(ll x) {
  if(x==parent[x]) return x;
  else return parent[x] = root(parent[x]);
}

bool same(ll x, ll y) {
  return root(x)==root(y);
}

ll unite(ll x, ll y) {
  x = root(x);
  y = root(y);
  if(siz[x]<siz[y]) swap(x, y);
  ll ans;
  if(x==y) {
    ans = 0;
    return ans;
  }
  else ans = siz[x]*siz[y];
  parent[y] = x;
  siz[x] += siz[y];
  return ans;
}

int main() {
  ll N, M;
  cin>>N>>M;
  for(ll i=0;i<N;++i) {
    parent[i] = i;
    siz[i] = 1;
  }
  ll A[M], B[M];
  for(ll i=0;i<M;++i) {
    cin>>A[i]>>B[i];
    A[i]--;
    B[i]--;
  }
  ll ans[M];
  ans[M-1] = N*(N-1)/2;
  for(ll i=M-2;i>=0;--i) {
    ans[i] = ans[i+1]-unite(A[i+1], B[i+1]);
  }
  for(ll i=0;i<M;++i) cout<<ans[i]<<endl;
}

