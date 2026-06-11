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

int N,M;
vector<ll> A;

set<pair<ll,int>> se[(1<<18)];
pair<int,int> mat[(1<<18)];
ll ans[(1<<18)];

int main(){
  cin>>N;
  M=(1<<N);
  A.resize(M);
  for(int i=0;i<M;i++) cin>>A[i];

  for(int i=1;i<M;i++){
    se[i].insert(mkp(-A[0],0));
    se[i].insert(mkp(-A[i],i));
  }

  for(int i=1;i<M;i++){
    for(int j=0;j<20;j++){
      if(i&(1<<j)){
        int a=mat[i^(1<<j)].first;
        int b=mat[i^(1<<j)].second;
        se[i].insert(mkp(-A[a],a));
        se[i].insert(mkp(-A[b],b));
      }
    }

    auto itr=se[i].begin();
    int a=(*itr).second;
    itr++;
    int b=(*itr).second;

    mat[i]=mkp(a,b);
    ans[i]=A[a]+A[b];
  }

  for(int i=1;i<M;i++) ans[i]=max(ans[i],ans[i-1]);
  for(int i=1;i<M;i++) cout<<ans[i]<<endl;

  return 0;
}
