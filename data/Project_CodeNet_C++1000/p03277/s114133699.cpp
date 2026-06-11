#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cmath>

using namespace std;

#define REP(i,n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> pint;

/// BIT from 蟻本を参考に
// [1, n]
const int MAX_N = 1<<18;
vector<ll> bit(MAX_N + 1);
ll n;
 
// sum(a[1]..a[n])
ll sum(int i, const int offset) {
  i += offset;
  ll s = 0;
  while(i > 0) {
    s += bit[i];
    i -= i & -i; 
  }
  return s;
}
 
// a[i] += x
void add(int i, const int x, const int offset) {
  i += offset;
  while(i < bit.size()) {
    bit[i] += x;
    //    cout << "A: " << i << " " << bit[i] << endl;
    i += i & -i;
  }
}
 
ll rev_count(const vector<int> &a) {
  fill(bit.begin(), bit.end(), 0LL);
  const int offset = a.size()+1; // -Nまでありうるので，N+1かさあげ
  n = a.size() * 2 + 2;
  //  const int offset = a.size() + 1;
  ll ans = 0;
  int sum_v = 0; 
  add(sum_v, 1, offset); // 自分との比較のために追加
  REP(j,a.size()) {
    sum_v += a[j];
    ans += sum(sum_v, offset); // <= の条件のとき
    //cout << j << ":" << a[j] << ":"<< sum_v << ":" << ans << endl;
    add(sum_v, 1, offset);
  }
  return ans;
}

ll solve(const vector<ll> &data) {
  const int N = data.size();
  ll B = N; B *= (N+1); B/=2LL; B++; B/=2LL;
  //cout << "Border = " << B << endl;
  vector<int> cmp_v(N,0);
#ifdef DEBUG
  for(int i = 0; i <= 5; i++) {
    cout << "Go....." << i << endl;
    REP(j, N) {
      cmp_v[j] = data[j] >= i ? +1 : -1;
      cout << j << data[j] << cmp_v[j] << endl;
    }
    ll ret = rev_count(cmp_v);
    
    cout << i << " " << ret << endl;
  }
  return 0;
#endif
  ll low = 0, high = 1LL<<60;
  while(low + 1 < high) {
    ll mid = (low + high) / 2LL;
    REP(j, N) {
      cmp_v[j] = data[j] >= mid ? +1 : -1;
    }
    ll ret = rev_count(cmp_v);
    //cout << mid << " " << ret << endl;
    if(ret >= B) low = mid;
    else high = mid;
  }
  return low;
}

int main() {
  int N; cin>>N;
  vector<ll> a(N);
  vector<ll> bit(2*N+10, 0);
  REP(i,N) cin>>a[i];
  ll ans = a[0];
  if(N>1) ans = solve(a);
  cout << ans << endl;
  return 0;
}
