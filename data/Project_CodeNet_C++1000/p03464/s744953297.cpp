#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> p_ll;

template<class T>
void debug(T itr1, T itr2) { auto now = itr1; while(now<itr2) { cout << *now << " "; now++; } cout << endl; }
#define repr(i,from,to) for (int i=(int)from; i<(int)to; i++)
#define rep(i,N) repr(i,0,N)
#define per(i,N) for (int i=(int)N-1; i>=0; i--)

const ll MOD = pow(10,9)+7;
const ll LLINF = pow(2,61)-1;
const int INF = pow(2,30)-1;


int main() {
  int K; cin >> K;
  ll A[K]; rep(i,K) cin >> A[i];
  ll ma = 2, mi = 2;
  per(i,K) {
    if (ma<A[i]) { cout << -1 << endl; return 0; }
    if (ma%A[i]&&mi%A[i]&&ma/A[i]==mi/A[i]) { cout << -1 << endl; return 0; }
    ma = (ma/A[i]+1)*A[i]-1;
    mi = ((mi-1)/A[i]+1)*A[i];
    // cout << mi << " " << ma << endl;
  }
  cout << mi << " " << ma << endl;
  return 0;
}