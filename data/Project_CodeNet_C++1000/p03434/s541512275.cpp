#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG

int main() {
  int N;
  cin >> N;
  vector<int> vec(N);
  for (int i; i < N; i++) cin >> vec[i];
  sort(vec.begin(), vec.end());
  reverse(vec.begin(),vec.end());

  int alice = 0, bob = 0;
  for (int i; i < N; i++) {
    if (i%2 == 0) alice += vec[i];
    else bob += vec[i];
  }
  cout << alice - bob << endl;
}