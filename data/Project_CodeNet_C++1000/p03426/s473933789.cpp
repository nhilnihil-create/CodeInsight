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
  int H, W, D;
  cin>>H>>W>>D;
  map<int, pair<int, int> > amap;
  int tmp;
  for(int i=0;i<H;++i) {
    for(int j=0;j<W;++j) {
      cin>>tmp;
      amap[tmp] = mp(i, j);
    }
  }
  vector<vector<int> > arr(D);
  for(int i=1;i<=H*W;++i) {
    if(i<=D) arr[i%D].push_back(0);
    else arr[i%D].push_back(abs(amap[i].fi-amap[i-D].fi)+abs(amap[i].se-amap[i-D].se));
  }
  /**
  for(int i=0;i<D;++i) {
    for(int j=0;j<arr[i].size();++j) {
      cout<<arr[i][j]<<" ";
    }
    cout<<endl;
  }
  **/
  for(int i=0;i<D;++i) {
    for(int j=1;j<arr[i].size();++j) {
      arr[i][j] += arr[i][j-1];
    }
  }
  int Q;
  cin>>Q;
  int L, R;
  for(int i=0;i<Q;++i) {
    cin>>L>>R;
    if(R%D==0) cout<<arr[R%D][(R-D)/D] - arr[L%D][(L-D)/D]<<endl;
    else cout<<arr[R%D][(R-R%D)/D] - arr[L%D][(L-L%D)/D]<<endl;
  }
}
