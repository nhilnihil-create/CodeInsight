#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
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
  int H, W, D;
  cin>>H>>W>>D;
  map<int, pair<int, int> > amap;
  int A;
  for(int i=0;i<H;++i) {
    for(int j=0;j<W;++j) {
      cin>>A;
      amap[A] = mp(i, j);
    }
  }
  vector<vector<int> >arr(D+1);
  int j;
  for(int i=1;i<=D;++i) {
    arr[i].push_back(0);
    j = 1;
    while(i+j*D<=H*W) {
      arr[i].push_back(arr[i][j-1]+abs(amap[i+j*D].fi-amap[i+(j-1)*D].fi)+abs(amap[i+j*D].se-amap[i+(j-1)*D].se));
      j++;
    }
  }
  int Q;
  cin>>Q;
  int L, R;
  int index;
  for(int i=0;i<Q;++i) {
    cin>>L>>R;
    index = L%D;
    if(index==0) index = D;
    cout<<arr[index][(R-index)/D] - arr[index][(L-index)/D]<<endl;
  }
}
