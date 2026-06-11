#include <iostream>
#include <string>
#include <vector>

#define rep(i,n) for (int i = 0; i < (n); ++i)

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {
  int N;
  string S;
  cin >> N >> S;

  int mx = 0;
  rep(i, N) {
    vector<bool> X(26, false);
    vector<bool> Y(26, false);
    for(int j = 0; j < i; j++) {
      X[S[j]-'a'] = true;
    }
    for(int j = i; j < N; j++) {
      Y[S[j]-'a'] = true;
    }

    int count = 0;
    rep(j, X.size()) {
      if (X[j] && Y[j]) count++;
    }
    if (mx < count) mx = count;
  }

  cout << mx << endl;

  return 0;
}
