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
  int X, Y, Z, K;
  cin>>X>>Y>>Z>>K;
  vector<ll> A(X), B(Y), C(Z);
  for(int i=0;i<X;++i) cin>>A[i];
  for(int i=0;i<Y;++i) cin>>B[i];
  for(int i=0;i<Z;++i) cin>>C[i];
  sort(A.begin(), A.end());
  sort(B.begin(), B.end());
  sort(C.begin(), C.end());
  int index1=X-1, index2=Y-1, index3=Z-1;
  vector<ll> ans;
  ll tmpans1, tmpans2, tmpans3;
  priority_queue<tuple<ll, int, int, int> > que;
  que.push(make_tuple(A[index1]+B[index2]+C[index3], index1, index2, index3));
  map<tuple<int, int, int>, int> amap;
  tuple<ll, int, int, int> state;
  while(true) {
    state = que.top();que.pop();
    index1 = get<1>(state);
    index2 = get<2>(state);
    index3 = get<3>(state);
    if(amap[make_tuple(index1, index2, index3)]>0) continue;
    amap[make_tuple(index1, index2, index3)]++;
    ans.push_back(A[index1]+B[index2]+C[index3]);
    if(ans.size()==K) break;
    if(index1>0) que.push(make_tuple(A[index1-1]+B[index2]+C[index3], index1-1, index2, index3));
    if(index2>0) que.push(make_tuple(A[index1]+B[index2-1]+C[index3], index1, index2-1, index3));
    if(index3>0) que.push(make_tuple(A[index1]+B[index2]+C[index3-1], index1, index2, index3-1));
  }
  for(int i=0;i<K;++i) cout<<ans[i]<<endl;
}

