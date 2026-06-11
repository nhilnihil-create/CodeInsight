#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, N) for (int i = 0; i < (int)N; i++)
const ll MOD = pow(10,9)+7;
const ll LLINF = pow(2,61)-1;
const int INF = pow(2,30)-1;


int main() {
  int N; cin >> N;
  string S; cin >> S;
  int Q; cin >> Q;
  int k[Q]; rep(i,Q) cin >> k[i];
  rep(q,Q) {
    ll d = 0, m = 0, dm = 0;
    ll result = 0;
    rep(i,N) {
      if (i>=k[q]) {
        if (S[i-k[q]]=='D') { d--; dm -= m; }
        else if (S[i-k[q]]=='M') m--;
      }
      if (S[i]=='D') d++;
      else if (S[i]=='M') { m++; dm += d; }
      else if (S[i]=='C') result += dm;
    }
    cout << result << endl;
  }
  return 0;
}