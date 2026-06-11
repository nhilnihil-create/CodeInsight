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

bool judge(vp ls,int p,int N) {
  reverse(rng(ls));
  int l=1,r=N;
  rep(i,sz(ls)) {
    int x = ls[i].second;
    if(ls[i].first) {
      if(x==1) {
        l = max(1,l-1);
      } else {
        r = min(N,r+1);
      }
    } else {
      if(x==1) {
        r--;
      } else {
        l++;
      }
    }
    if(l>r) {
      return false;
    }
  }
  return l<=p&&p<=r;
}
  
int main() {
  int H,W,N;
  cin >> H >> W >> N;
  int sr,sc;
  cin >> sr >> sc;
  string taka,aoki;
  cin >> taka >> aoki;
  vp h,w;
  rep(i,N) {
    switch (taka[i]) {
      case 'L':
        w.push_back(P(0,-1));
        break;
      case 'R':
        w.push_back(P(0,1));
        break;
      case 'U':
        h.push_back(P(0,-1));
        break;
      case 'D':
        h.push_back(P(0,1));
        break;
    }
    switch (aoki[i]) {
      case 'L':
        w.push_back(P(1,-1));
        break;
      case 'R':
        w.push_back(P(1,1));
        break;
      case 'U':
        h.push_back(P(1,-1));
        break;
      case 'D':
        h.push_back(P(1,1));
        break;
    }
  } 
  if(judge(h,sr,H) && judge(w,sc,W)) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}