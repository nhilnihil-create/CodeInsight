#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
  int A;
  cin >> A;
  int AAA;
  vector<int> vec(A);
  rep(i, A) {
    cin >> AAA;
    vec.at(i) = AAA;
  }
  sort(vec.begin(), vec.end());
  reverse(vec.begin(), vec.end());
  int X = 0;
  for(int i = 0; i < vec.size(); i += 2) {
    X += vec.at(i);
  }
  int Y = 0;
  rep(i, vec.size()) {
    Y += vec.at(i);
  }
  cout << X - (Y - X) << endl;
}