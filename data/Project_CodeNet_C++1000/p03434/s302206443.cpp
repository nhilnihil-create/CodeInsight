#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

using namespace std;

int main() {
  int N;
  cin >> N;

  int input;
  vector<int> vec;
  rep (i, N) {
    cin >> input;
    vec.push_back(input);
  }
  sort(vec.begin(), vec.end());
  reverse(vec.begin(), vec.end());
  int A = 0, B = 0;
  rep(i, N) {
    if (i % 2 == 0) {
      A += vec.at(i);
    } else {
      B += vec.at(i);
    }
  }
  cout << A - B << endl;
}
