#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int64_t> Lucas = { 2, 1, };
  for (int i = 0; i < N; i++) {
    int64_t x = Lucas.at(i) + Lucas.at(i+1);
    Lucas.push_back(x);
  }
  cout << Lucas.at(N) << endl;
}