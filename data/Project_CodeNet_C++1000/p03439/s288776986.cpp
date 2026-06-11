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
  int N; cin >> N;
  cout << 0 << endl;
  string r0; cin >> r0;
  string rnow;
  int l = 0, r = N-1;
  while(l!=r) {
    int mid = (l+r+1)/2;
    cout << mid << endl;
    cin >> rnow;
    if (rnow=="Vacant") break;
    if (rnow==r0^(mid%2)) l = mid;
    else r = mid-1;
  }
  return 0;
}