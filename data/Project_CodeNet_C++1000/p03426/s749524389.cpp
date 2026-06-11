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

int main() {
  int H, W, D; cin>>H>>W>>D;
  vector<vector<int> > A(H, vector<int>(W));
  map<int, pair<int, int> > amap;
  for(int i=0;i<H;++i) {
    for(int j=0;j<W;++j) {
      cin>>A[i][j];
      if(A[i][j]>D) {
        amap[A[i][j]-D] = mp(i, j);
      }
    }
  }
  int ans[H*W+1];
  for(int i=0;i<=H*W;++i) ans[i] = 0;
  for(int i=0;i<H;++i) {
    for(int j=0;j<W;++j) {
      if(A[i][j]+D>H*W) continue;
      ans[A[i][j]] = abs(amap[A[i][j]].fi-i)+abs(amap[A[i][j]].se-j);
    }
  }
  vector<vector<int> > ansarr(D);
  for(int i=0;i<D;++i) ansarr[i].push_back(0);
  for(int i=1;i<H*W;++i) {
    if(ans[i]==0) break;
    ansarr[i%D].push_back(ans[i]);
  }
  for(int i=0;i<D;++i) {
    for(int j=1;j<ansarr[i].size();++j) ansarr[i][j] += ansarr[i][j-1];
  }
  /**
  for(int i=0;i<D;++i) {
    cout<<i<<endl;
    for(int j=0;j<ansarr[i].size();++j) cout<<ansarr[i][j]<<" ";
    cout<<endl;
  }
  **/
  int Q;
  cin>>Q;
  int l, r;
  int ans1[Q];
  for(int i=0;i<Q;++i) {
    cin>>l>>r;
    if(l%D==0) ans1[i] = ansarr[l%D][r/D-1]-ansarr[l%D][l/D-1];
    else ans1[i] = ansarr[l%D][(r-l%D)/D]-ansarr[l%D][(l-l%D)/D];
  }
  for(int i=0;i<Q;++i) cout<<ans1[i]<<endl;
}
