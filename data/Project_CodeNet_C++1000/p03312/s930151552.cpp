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
  int N;
  cin>>N;
  vector<ll> A(N);
  for(int i=0;i<N;++i) cin>>A[i];
  for(int i=1;i<N;++i) A[i] += A[i-1];
  int index1, index2;
  int index11, index22;
  ll P, Q, R, S;
  ll ans = big;
  ll maxnum, minnum;
  for(int i=0;i<N;++i) {
    index1 = upper_bound(A.begin(), A.begin()+i, A[i]/2) - A.begin();
    index2 = upper_bound(A.begin()+i+1, A.end(), A[i]+(A[N-1]-A[i])/2) - A.begin();
    for(int j=-1;j<=1;++j) {
      for(int k=-1;k<=1;++k) {
        index11 = index1 + j;
        index22 = index2 + k;
        if(0<=index11 && index11<i && i<index22 && index22<N-1) {
          P = A[index11];
          Q = A[i] - A[index11];
          R = A[index22] - A[i];
          S = A[N-1] - A[index22];
          maxnum = max(P, max(Q, max(R, S)));
          minnum = min(P, min(Q, min(R, S)));
          ans = min(ans, maxnum-minnum);
        }
      }
    }
  }
  cout<<ans<<endl;
}

