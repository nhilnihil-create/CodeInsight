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
  int l = 0;
  int r = N-1;
  vi seat(N,-1);
  cout << l << endl << flush;
  string s;
  cin >> s;
  if(s == "Vacant") {
    return 0;
  }
  seat[l] = s == "Male";
  cout << r << endl << flush;
  cin >> s;
  if(s == "Vacant") {
    return 0;
  }
  seat[r] = s == "Male";
  while(1) {
    int m = (l+r)/2;
    cout << m << endl << flush;
    cin >> s;
    if(s == "Vacant") return 0;
    bool male = s == "Male";
    seat[m] = male;
    if((seat[l] && male) || (!seat[l] && !male)) {
      if((m-l)%2 != 0) {
        r = m;
        continue;
      }
    }
    if((seat[l] && !male) || (!seat[l] && male)) {
      if((m-l)%2 == 0) {
        r = m;
        continue;
      }
    }
    if((seat[r] && male) || (!seat[r] && !male)) {
      if((r-m)%2 != 0) {
        l = m;
        continue;
      }
    }
    if((seat[r] && !male) || (!seat[r] && male)) {
      if((r-m)%2 == 0) {
        l = m;
        continue;
      }
    }
    
  }
  return 0;
}