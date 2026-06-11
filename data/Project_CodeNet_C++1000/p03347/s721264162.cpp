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
  rep(i,N) {
    cin >> A[i];
  }
  if(A[0] != 0) {
    cout << -1 << endl;
    return 0;
  }
  bool ok = true;
  rep(i,N-1) {
    if(A[i+1] - A[i] > 1) {
      ok = false;
      break;
    }
  }
  if(!ok) {
    cout << -1 << endl;
    return 0;
  }
  int p = 0;
  ll cnt = 0;
  srep(i,1,N) {
    if(A[i] == p+1) {
      cnt++;
      p++;
      continue;
    } else if(A[i] == 0) {
      p = 0;
      continue;
    } else {
      cnt += A[i];
      p = A[i];
      continue;
    }
  }
  cout << cnt << endl;
  return 0;
}