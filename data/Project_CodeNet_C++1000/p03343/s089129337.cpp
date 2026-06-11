#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> p_ll;

template<class T>
void debug(T itr1, T itr2) { auto now = itr1; while(now<itr2) { cout << *now << " "; now++; } cout << endl; }
#define repr(i,from,to) for (int i=(int)from; i<(int)to; i++)
#define all(vec) vec.begin(), vec.end()
#define rep(i,N) repr(i,0,N)
#define per(i,N) for (int i=(int)N-1; i>=0; i--)

const ll MOD = pow(10,9)+7;
const ll LLINF = pow(2,61)-1;
const int INF = pow(2,30)-1;


int main() {
  int N, K, Q; cin >> N >> K >> Q;
  ll A[N]; rep(i,N) cin >> A[i];

  if (Q==1) { cout << 0 << endl; return 0; }
  ll result = INF;
  rep(i,N) {
    vector<ll> num, now;
    rep(j,N+1) {
      if (j!=i&&j!=N&&A[j]>=A[i]) now.push_back(A[j]);
      else if (j!=i) {
        sort(all(now));
        rep(i,now.size()-K+1) num.push_back(now[i]);
        now.clear();
      }
    }
    sort(all(num));
    // debug(all(num));
    if (num.size()>=Q-1) result = min(result, num[Q-2]-A[i]);
  }
  cout << result << endl;
  return 0;
}