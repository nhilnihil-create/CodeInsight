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
  int N; cin >> N;
  int count = N%2 ? 2*(N/2*(N/2-1)) + N-1 : 2*(N/2*(N/2-1));
  cout << count << endl;
  int p = N-N%2;
  repr(i,1,p/2) {
    rep(j,p-i*2) cout << i << " " << i+j+1 << endl;
    rep(j,p-i*2) cout << p-(i-1) << " " << p-(i+j) << endl;
  }
  if (N%2) repr(i,1,N) cout << i << " " << N << endl;
  return 0;
}