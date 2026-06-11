#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> vec(N);
  for(int i = 0;i < N;++i) {
    cin >> vec.at(i);
  }
  sort(vec.begin(), vec.end());
  int a = vec.at(0);
  reverse(vec.begin(), vec.end());
  int b = vec.at(0);
  b = b - a;
  cout << b << endl;
}
