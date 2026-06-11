#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
#define FOR(i, begin, end) for(int i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(int i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
constexpr int MOD = 1000000007;
constexpr int INF = 2147483647;
void yes(bool expr) {
  cout << (expr ? "Yes" : "No") << "\n";
}
struct Segment_Sum {
private:
  lint n;
  vector<lint> node;
public:
  Segment_Sum(lint N) {
    lint sz = N;
    n = 1; while(n < sz) n *= 2;
    node.resize(2*n-1, 0);
  }
  void update(lint x) {
    x += (n - 1);
    node[x] += 1;
    while(x > 0) {
      x = (x - 1) / 2;
      node[x] = node[2*x+1] + node[2*x+2];
    }
  }
  lint getsum(int a, int b, int k=0, int l=0, int r=-1) {
    if(r < 0) r = n;
    if(r <= a || b <= l) return 0;
    if(a <= l && r <= b) return node[k];
    lint vl = getsum(a, b, 2*k+1, l, (l+r)/2);
    lint vr = getsum(a, b, 2*k+2, (l+r)/2, r);
    return vl + vr;
  }
};
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  lint N;
  cin >> N;
  vector<lint> A(N);
  REP(i, N) cin >> A[i];
  lint l = 0;
  lint r = 1<<30;
  lint m = 0;
  if(N == 1) {
    cout << A[0] << endl;
    return 0;
  }
  while(l < r) {
    m = (l + r) / 2;
    vector<lint> S(N+1);
    REP(i, N) {
      if(A[i] >= m) {
        S[i+1] = 1;
      } else {
        S[i+1] = -1;
      }
    }
    FOR(i, 1, N+1) {
        S[i] += S[i-1];
    }
    lint ans = 0;
    Segment_Sum seg(2*N+10);
    REP(i, N+1) {
      ans += seg.getsum(0, N+1+S[i]+1);
      seg.update(N+1+S[i]);
    }
    //cout << l << " " << r << " " << ans << endl;
    lint target = N*(N+1)/2/2;
    if(ans < target) {
      if(l == m) {
        r--; m--;
        break;
      } else {
        r=m;
      }
      
    } else {
      if(l == m) {
        break;
      } else {
        l=m;
      }
      
    }
  }
  cout << m << endl;
}