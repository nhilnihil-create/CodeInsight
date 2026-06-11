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
  ll K;
  cin >> K;
  vl A(K);
  rep(i,K) {
    cin >> A[i];
  }
  reverse(rng(A));
  if(A[0] > 2) {
    cout << -1 << endl;
    return 0;
  }
  ll a = A[0];
  ll b = 2*A[0]-1;
  srep(i,1,K) {
    if(A[i-1] == A[i]) continue;
    ll bb = b;
    ll ba = a;
    ll x = (A[i-1]+(b/A[i-1])*A[i-1])/A[i];
    if(A[i]*x >= A[i-1]+(b/A[i-1])*A[i-1]) {
      x--;
    }
    ll y = A[i]-1;
    b = A[i]*x+y;
    if(A[i] >= a) {
      a = A[i];
    } else {
      a = ((a+A[i]-1)/A[i])*A[i];
    }
    if(a > (bb)) {
      cout << -1 << endl;
      return 0;
    }
  }
  cout << a << " " << b << endl;
  return 0;
}