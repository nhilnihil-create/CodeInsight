#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
using vi = vector<int>;
void ins() {}
template<class T,class... Rest>void ins(T& v,Rest&... rest){cin>>v;ins(rest...);}
#define rep(i,n) for(int i=0,_i=(n);i<_i;++i)
template<class T>bool chmin(T &a,const T &b){if(b<a){a=b;return 1;}return 0;}
int main() {
  int N, A, B, C;
  ins(N, A, B, C);

  vi l(N);
  rep(i, N)
    cin >> l[i];

  int ans = 1e9;
  rep(_p, pow(4, N)) {
    int pattern = _p;
    vi v(4, 0), sum(4, 0);
    rep(i, N) {
      ++v[pattern % 4];
      sum[pattern % 4] += l[i];
      pattern /= 4;
    }
    if (v[0] + v[1] + v[2] < 3 || v[0] * v[1] * v[2] == 0)
      continue;
    chmin(ans, (v[0]-1) * 10 + abs(A-sum[0]) + (v[1]-1) * 10 + abs(B-sum[1]) + (v[2]-1) * 10 + abs(C-sum[2]));
  }
  cout << ans << endl;

  return 0;
}
