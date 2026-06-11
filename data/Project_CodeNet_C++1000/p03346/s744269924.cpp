#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, N) for (int i = 0; i < (int)N; i++)
const ll MOD = pow(10,9)+7;
const ll LLINF = pow(2,61)-1;
const int INF = pow(2,30)-1;

int main() {
  int N; cin >> N;
  int P[N]; rep(i,N) { cin >> P[i]; P[i]--; }
  int seq[N]; rep(i,N) seq[P[i]]= i;
  int back[N]; fill_n(back,N,-1);
  rep(i,N-1) {
    if (seq[i+1]>seq[i]) {
      back[seq[i+1]] = seq[i];
    }
  }

  int r[N]; fill_n(r,N,1);
  rep(i,N) {
    if (back[i]!=-1) r[i] = r[back[i]]+1;
  }
  int rmax = 0; rep(i,N) rmax = max(rmax, r[i]);
  int result = N - rmax;
  cout << result << endl;
  return 0;
}