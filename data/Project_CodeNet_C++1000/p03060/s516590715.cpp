#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
  int N;
  cin >> N;
  vector<int> vec(N);
  int X;
  int sum = 0;
  rep(i, N) {
    cin >> vec.at(i);
  }
  rep(i, N) {
      cin >> X;
  vec.at(i) -= X;
    if(vec.at(i) > 0) {
      sum += vec.at(i);
    }
  }
  cout << sum << endl;
}