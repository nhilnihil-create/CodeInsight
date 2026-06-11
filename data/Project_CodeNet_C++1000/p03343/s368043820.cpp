#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
#include <iomanip>
#include <set>
#include <tuple>
#define mkp make_pair
#define mkt make_tuple
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;

#include <functional>
#include <climits>

//SegmentTree<int> seg(N,[](int a,int b){return min(a,b);},INT_MAX);
template< typename T>
class SegmentTree{
public:

  using F = function<T(T,T)>;

  int n;
  vector<T> tree;
  const F operation;
  const T def;

  SegmentTree(int size,F _operation,T _def):operation(_operation),def(_def){
    n=1;
    while(n<size) n*=2;
    tree.resize(2*n-1,def);
  }

  void initialize(vector<T> v){
    int vSize=v.size();
    n=1;
    while(n<vSize) n*=2;
    tree.resize(2*n-1,def);

    for(int i=0;i<vSize;i++) tree[i+n-1]=v[i];
    for(int i=n-2;i>=0;i--) tree[i]=operation(tree[2*i+1],tree[2*i+2]);
  }

  void update(int index,T value){
    index+=n-1;

    tree[index]=value;
    while(index>0){
      index=(index-1)/2;
      tree[index]=operation(tree[2*index+1],tree[2*index+2]);
    }
  }

  T query(int a,int b,int k=0,int l=0,int r=-1){//[a,b),getMin(a,b,0,0,-1)
    if(r<0) r=n;

    if(r<=a||b<=l) return def;
    else if(a<=l&&r<=b) return tree[k];
    else{
      T lval=query(a,b,2*k+1,l,(l+r)/2);
      T rval=query(a,b,2*k+2,(l+r)/2,r);
      return operation(lval,rval);
    }
  }
};


int N,K,Q;
vector<ll> A;

int main(){
  cin>>N>>K>>Q;
  A.resize(N);
  rep(i,N) cin>>A[i];

  vector<pair<ll,int>> v;
  for(int i=0;i<N;i++) v.push_back(mkp(A[i],i));
  sort(v.begin(),v.end());

  ll ans=v.back().first-v[0].first;
  for(int i=0;i<N;i++){
      int now=v[i].second;
      SegmentTree<int> seg(N+2,[](int a,int b){return a+b;},0);
      int sum=0;
      int last=0;
      set<int> se;
      se.insert(-1);
      se.insert(N);
      for(int j=0;j<i;j++) se.insert(v[j].second);

      for(int j=i;j<N;j++){
          if(sum>=Q) break;
          int tar=v[j].second;
          auto itr=se.lower_bound(tar);
          int r=*itr;
          itr--;
          int l=*itr;

          int used=seg.query(l+1,r);
          int num=r-l-1-used;
          if(num>=K){
              last=A[tar];
              sum++;
              seg.update(tar,1);
          }else{
              se.insert(tar);
          }
      }
      if(sum>=Q) ans=min(ans,last-A[now]);
  }

  cout<<ans<<endl;


  return 0;
}
