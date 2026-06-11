#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
  int A, B;
  cin >> A >> B;
  int N = B - A;
  vector<int> vec(999);
  rep(i, 999) {
    if(i == 0) {
      vec.at(i) = 1;
    }
    else {
      vec.at(i) = vec.at(i-1)+i+1;
    }
  }
  cout << vec.at(N-1) - B << endl;
}