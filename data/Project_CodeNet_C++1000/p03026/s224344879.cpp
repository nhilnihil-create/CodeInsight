#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <limits>
#include <utility>
#include <cmath>
#include <functional>
#include <iomanip>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;

#define _overload3(_1,_2,_3,name,...) name
#define _all1(a) (a).begin(),(a).end()
#define _all2(a,n) (a),(a)+n
#define all(...) _overload3(__VA_ARGS__,_all1,_all2,)(__VA_ARGS__)
#define _rep(i,n) for(int i=0;i<(n);++i)
#define repi(i,a,b) for(int i=(a);i<(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)

#define rrep(i,n) for(int i=(n);i>=0;--i)
#define iter(it,v) for(auto it=v.begin();it!=v.end();++it)
#define in(v) cin>>v;
#define out(v) cout<<v<<"\n"
const int MOD = 1e9+7;
const int INF = numeric_limits<int>::max();
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
template<typename Iterator>void print(const Iterator s, const Iterator t) { if(s==t)return;for(auto it=s;it+1!=t;++it)cout<<*it<<" ";cout<<*(t-1)<<"\n"; }
template<class T1,class T2>ostream& operator<<(ostream& out,const pair<T1,T2>& rhs){out<<"("<<rhs.first<<", "<<rhs.second<<")";return out;}

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  int N; in(N);

  int A[N-1], B[N-1], c[N];
  bool visited[N];
  fill(all(visited, N), false);

  rep(i, N-1) {
    in(A[i]); in(B[i]);
    --A[i]; --B[i];
  }
  int sum = 0;
  rep(i, N) {
    in(c[i]);
    sum += c[i];
  }
  sort(all(c, N));
  reverse(all(c, N));
  out(sum-c[0]);
  visited[A[0]] = visited[B[0]] = true;

  int ans[N];
  ans[A[0]] = c[0];
  ans[B[0]] = c[1];
  rep(i, 1, N-1) {
    rep(j, N-1) {
      if (visited[A[j]] != visited[B[j]]) {
        if (!visited[A[j]])
          ans[A[j]] = c[i+1];
        else
          ans[B[j]] = c[i+1];
        visited[A[j]] = visited[B[j]] = true;
        break;
      }
    }
  }
  rep(i, N) {
    cout << ans[i];
    if (i + 1 != N)
      cout << " ";
  }
  cout << "\n";

  return 0;
}
