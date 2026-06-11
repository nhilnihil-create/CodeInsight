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
  int X, Y, Z, K;
  cin>>X>>Y>>Z>>K;
  vector<ll> A(X), B(Y), C(Z);
  for(int i=0;i<X;++i) cin>>A[i];
  for(int i=0;i<Y;++i) cin>>B[i];
  for(int i=0;i<Z;++i) cin>>C[i];
  sort(A.begin(), A.end(), greater<ll>());
  sort(B.begin(), B.end(), greater<ll>());
  sort(C.begin(), C.end(), greater<ll>());
  
  priority_queue<tuple<ll, int, int, int> > que;
  que.push(make_tuple(A[0]+B[0]+C[0], 0, 0, 0));
  tuple<ll, int, int, int> state;
  ll score;
  int aindex, bindex, cindex;
  ll ans[K];
  map<tuple<int, int, int>, int> amap;
  for(int i=0;i<K;++i) {
    state = que.top();que.pop();
    score = get<0>(state);
    ans[i] = score;
    aindex = get<1>(state);
    bindex = get<2>(state);
    cindex = get<3>(state);
    if(aindex+1<X && amap[make_tuple(aindex+1, bindex, cindex)]==0) {
      que.push(make_tuple(score-A[aindex]+A[aindex+1], aindex+1, bindex, cindex));
      amap[make_tuple(aindex+1, bindex, cindex)]++;
    }
    if(bindex+1<Y && amap[make_tuple(aindex, bindex+1, cindex)]==0) {
      que.push(make_tuple(score-B[bindex]+B[bindex+1], aindex, bindex+1, cindex));
      amap[make_tuple(aindex, bindex+1, cindex)]++;
    }
    if(cindex+1<Z && amap[make_tuple(aindex, bindex, cindex+1)]==0) {
      que.push(make_tuple(score-C[cindex]+C[cindex+1], aindex, bindex, cindex+1));
      amap[make_tuple(aindex, bindex, cindex+1)]++;
    }
  }
  for(int i=0;i<K;++i) cout<<ans[i]<<endl;
}

