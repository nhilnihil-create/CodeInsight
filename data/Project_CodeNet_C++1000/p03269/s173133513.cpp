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
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
#define EPS (1e-10)
#define equals(a, b) (fabs((a)-(b)) < EPS)
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
  int L;
  cin >> L;
  int N;
  {
    int k=1;
    N=0;
    while(k<=L) {
      k = k<<1;
      N++;
    }
  }
  v(vp) from(N);
  rep(i,N-1) {
    from[i].emplace_back(i+1,0);
    from[i].emplace_back(i+1,1<<i);
  }
  rep(i,N-1) {
    if((L>>(i))&1) {
      int k=L/(1<<(i));
      k--;
      from[i].emplace_back(N-1,k*(1<<(i)));
    }
  }
  int cnt=0;
  rep(i,N) {
    cnt += sz(from[i]);
  }
  cout << N << " " << cnt << endl;
  rep(i,N) {
    for(auto p:from[i]) {
      cout << i+1 << " " << p.first+1 << " " << p.second << endl;
    }
  }
  return 0;
}
