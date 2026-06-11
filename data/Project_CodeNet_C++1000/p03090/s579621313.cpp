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
  int N;
  cin>>N;
  int S;
  if(N%2!=0) S = (N-1)*N/2;
  else S = (N-1)*N/2-1;
  vector<pair<int, int> > ans;
  map<int, int> amap;
  for(int i=1;i<=N;++i) amap[i] = S;
  int sum = N*(N+1)/2;
  int tmp;
  for(int i=N;i>0;--i) {
    sum -= i;
    tmp = sum - amap[i];
    for(int j=1;j<i;++j) {
      if(j==tmp) continue;
      ans.push_back(mp(i, j));
      amap[j] -= i;
    }
  }
  cout<<ans.size()<<endl;
  for(int i=0;i<ans.size();++i) {
    cout<<ans[i].fi<<" "<<ans[i].se<<endl;
  }
}

