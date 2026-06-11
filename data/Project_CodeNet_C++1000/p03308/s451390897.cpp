#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
  int A;
  cin >> A;
  vector<int> vec(A);
  int AAA;
  rep(i, A) {
    cin >> AAA;
    vec.at(i) = AAA;
  }
  sort(vec.begin(), vec.end());
  cout << vec.at(A - 1) - vec.at(0) << endl;
}