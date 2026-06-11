#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, N) for (int i = 0; i < (int)N; i++)
const ll MOD = pow(10,9)+7;
const ll LLINF = pow(2,61)-1;
const int INF = pow(2,30)-1;


int main() {
  ll N, A, B; cin >> N >> A >> B;
  int p[N]; rep(i,N) p[i]=i+1;
  if (A*B<N||A+B>N+1) { cout << -1 << endl; return 0; }

  int pos = 0;
  A = N-A;
  while(A>=B-1) {
    if (pos+B>N) break;
    reverse(p+pos,p+pos+B);
    pos += B;
    A -= B-1;
  }
  reverse(p+pos,p+pos+A+1);
  rep(i,N) cout << p[i] << " "; cout << endl;
  return 0;
}