#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
  int N;
  cin >> N;
  vector<string> vec(N);
  int S;
  int ans = 0;
  char C = 'X';
  rep(i, N) {
    cin >> vec.at(i);
    if(i == 0) {
      C = vec.at(i).at(0);
    }
    if(vec.at(i).at(0) != C) {
      ans++;
    }
    S = vec.at(i).size();
    C = vec.at(i).at(S-1);
    rep(j, i) {
      if(vec.at(i) == vec.at(j)) {
        ans++;
        break;
      }
    }
    if(ans > 0) {
      break;
    }
    if(i == N - 1) {
      break;
    }
  }
  if(ans > 0) {
    cout << "No" << endl;
  }
  else {
    cout << "Yes" << endl;
  }
}
