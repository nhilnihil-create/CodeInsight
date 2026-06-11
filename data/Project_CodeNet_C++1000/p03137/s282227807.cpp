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
  vector<int> X(M);
  for(int i=0;i<M;++i) cin>>X[i];
  sort(X.begin(), X.end());
  vector<int> dist(M-1);
  for(int i=0;i<M-1;++i) {
    dist[i] = X[i+1]-X[i];
  }
  sort(dist.begin(), dist.end(), greater<int>());
  int ans = 0;
  for(int i=N-1;i<M-1;++i) {
    ans += dist[i];
  }
  cout<<ans<<endl;
}

