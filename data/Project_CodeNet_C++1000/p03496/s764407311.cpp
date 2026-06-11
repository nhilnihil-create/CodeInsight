#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
#define rng(a) a.begin(),a.end()
#define sz(x) (int)(x).size()
#define uni(x) x.erase(unique(rng(x)),x.end())
#define show(x) cout<<#x<<" = "<<x<<endl;
#define PQ(T) priority_queue<T,v(T),greater<T> >
#define newline puts("")
#define v(T) vector<T>
#define vv(T) v(v(T))
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef set<int> S;
typedef queue<int> Q;
typedef queue<P> QP;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
const int MOD = 1000000007;
  
int main() {
  int N;
  cin >> N;
  vi A(N);
  P ma = P(-INF,-1);
  P mi = P(INF,-1);
  rep(i,N) {
    cin >> A[i];
    if(ma.first < A[i]) {
      ma = P(A[i],i);
    }
    if(mi.first > A[i]) {
      mi = P(A[i],i);
    }
  }
  vp op;
  if(abs(ma.first) >= abs(mi.first)) {
    rep(i,N) {
      if(i == ma.second) continue;
      op.push_back(P(ma.second,i));
      A[i] += ma.first;
    }
    op.push_back(P(ma.second,ma.second));
    A[ma.second] += ma.first;
    rep(i,N-1) {
      while(1) {
        if(A[i] <= A[i+1]) break;
        A[i+1] += A[i];
        op.push_back(P(i,i+1));
      }
    }
  } else {
    rep(i,N) {
      if(i == mi.second) continue;
      op.push_back(P(mi.second,i));
      A[i] += mi.first;
    }
    op.push_back(P(mi.second,mi.second));
    A[mi.second] += mi.first;
    drep(i,N-1) {
      while(1) {
        if(A[i] <= A[i+1]) break;
        A[i] += A[i+1];
        op.push_back(P(i+1,i));
      }
    }
  }
  
  
  cout << sz(op) << endl;
  rep(i,sz(op)) {
    cout << op[i].first+1 << " " << op[i].second+1 << endl;
  }
  return 0;
}