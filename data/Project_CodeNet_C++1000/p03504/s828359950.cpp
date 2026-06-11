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
  int N,C;
  cin >> N >> C;
  vv(P) A(C);
  rep(i,N) {
    int s,t,c;
    cin >> s >> t >> c;
    c--;
    A[c].push_back(P(s,t));
  }
  rep(i,C) {
    sort(rng(A[i]));
    vp a;
    rep(j,sz(A[i])) {
      if(j+1<sz(A[i]) && A[i][j].second == A[i][j+1].first) {
        int k = j+1;
        while(k+1<sz(A[i])&&A[i][k].second == A[i][k+1].first) {
          k++;
        }
        a.push_back(P(A[i][j].first,A[i][k].second));
        j = k;
      } else {
        a.push_back(A[i][j]);
      }
    }
    A[i] = a;
  }
  vi imos(100010,0);
  rep(i,sz(A)) {
    rep(j,sz(A[i])) {
      imos[A[i][j].first-1]++;
      imos[A[i][j].second]--;
    }
  }
  int ans = 0;
  int tmp = 0;
  rep(i,100010) {
    tmp += imos[i];
    ans = max(ans,tmp);
  }
  cout << ans << endl;
  return 0;
}