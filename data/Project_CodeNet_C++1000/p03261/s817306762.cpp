#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
using namespace std;

bool hantei(vector<string>& W) {
  int l = W.size();

  rep(i, 0, l-1) {
    if ( W[i].back() != W[i+1].front() ) return false;
  }

  rep(i, 0, l) {
    rep(j, i+1, l) {
      if ( W[i] == W[j] ) return false;
    }
  }

  return true;
}

int main() {
  int N;
  cin >> N;

  vector<string> W(N);
  rep(i, 0, N) cin >> W[i];

  cout << ( hantei(W) ? "Yes" : "No" ) << endl;
}
